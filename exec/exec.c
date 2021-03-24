/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 10:54:08 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/09 15:45:03 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_all	*g_all;

void	set_it(t_lst **it)
{
	t_cmd *cm;

	cm = (*it)->cont;
	while (ft_is_in_charset('>', (cm)->pipe) ||
			ft_is_in_charset('<', (cm)->pipe))
	{
		*it = (*it)->next;
		cm = (*it)->cont;
	}
	if ((*it))
	{
		(*it) = (*it)->next;
		if ((*it))
			cm = (*it)->cont;
	}
}

void	exec_single_cmd(t_lst *cmd)
{
	t_cmd	*cm;

	cm = cmd->cont;
	if (cm->cmd && !exec_buildin(cmd))
	{
		if ((g_all->pid = fork()) < 0)
			pid_error();
		if (!g_all->pid)
			dup_fds(cm);
		if (!g_all->pid)
			exec_bin(cm);
		if (!g_all->pid)
			free_baby();
		close_fds(cmd);
		if (g_all->pid)
		{
			waitpid(g_all->pid, &(g_all->last_exit), 0);
			if (g_all->last_exit >= 256)
				g_all->last_exit /= 256;
			else
				g_all->last_exit += 128;
		}
	}
}

void	exec_redirnpipe(t_lst *cmd)
{
	t_lst	*it;
	pid_t	pid;
	int		i;

	it = cmd;
	i = 0;
	while (it)
	{
		i++;
		if ((pid = fork()) < 0)
			pid_error();
		if (!pid)
		{
			dup_fds(it->cont);
			close_fds(cmd);
			if (!exec_buildin(it))
				exec_bin(it->cont);
			free_baby();
		}
		set_it(&it);
	}
	close_fds(cmd);
	while (i-- >= 0)
		wait(&g_all->last_exit);
}

void	exec(void)
{
	t_lst	*it;

	it = g_all->cmds;
	errno = 0;
	if (!parse_syntax_cmds())
		return ;
	while (it)
	{
		if (errno == 12)
			return ;
		sub_vars(it->cont);
		parse_cmd(it->cont);
		if (!set_fds(it->cont))
			break ;
		ft_count_pipes(it->cont) ?
			exec_redirnpipe(it->cont) : exec_single_cmd(it->cont);
		it = it->next;
	}
	ft_lstclear(&g_all->cmds, free_redirnpipe);
	g_all->cmds = 0;
	g_all->pid = 0;
}
