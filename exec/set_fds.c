/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:02:55 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/10 14:02:55 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	set_fd_out(t_cmd *cmd, t_cmd *file, t_lst **it)
{
	int		fd;
	char	*fname;
	int		flags;

	fname = file->cmd[0];
	flags = !ft_strcmp(((t_cmd *)((*it)->cont))->pipe, ">>") ?
			O_APPEND : O_TRUNC;
	flags = O_CREAT | O_WRONLY | flags;
	if ((fd = open(fname, flags, 0755)) < 0)
		return (0);
	if (cmd->fout != 1)
		close(cmd->fout);
	cmd->fout = fd;
	*it = (*it)->next;
	return (1);
}

char	set_fd_in(t_cmd *cmd, t_cmd *file, t_lst **it)
{
	int		fd;
	char	*fname;
	int		flags;

	fname = file->cmd[0];
	flags = O_RDONLY;
	if (!ft_strcmp(&(cmd->pipe[1]), ">"))
	{
		cmd->fin = 0;
		fd = open(fname, O_CREAT | O_TRUNC, 0755);
		close(fd);
	}
	if ((fd = open(fname, flags, 0755)) < 0)
	{
		printf(RED"ls: %s: "NRM, fname);
		cmd_error();
		return (0);
	}
	if (cmd->fin != 0)
		close(cmd->fin);
	cmd->fin = fd;
	*it = (*it)->next;
	return (1);
}

char	set_fd_pipe(t_cmd *cmdout, t_cmd *cmdin)
{
	int		fd[2];
	int		fd_app;

	if (pipe(fd) < 0)
		pipe_error();
	if (!ft_strcmp(&(cmdout->pipe[1]), ">>") &&
	(fd_app = open(cmdin->cmd[0], O_CREAT | O_APPEND, 0755)))
		close(fd_app);
	if (!ft_strcmp(&(cmdout->pipe[1]), ">") &&
		(fd_app = open(cmdin->cmd[0], O_CREAT | O_TRUNC, 0755)))
		close(fd_app);
	cmdout->fout = fd[1];
	cmdin->fin = fd[0];
	return (1);
}

char	set_fds(t_lst *lst)
{
	t_cmd	*cmd;
	t_lst	*it;
	t_cmd	*cm;

	it = lst;
	while (it)
	{
		cmd = it->cont;
		cm = it->cont;
		while (it->next && !ft_strncmp(cmd->pipe, ">", 1))
			if ((cmd = it->next->cont) && !(set_fd_out(cm, cmd, &it)))
				return (0);
		while (it->next && !ft_strncmp(cmd->pipe, "<", 1))
			if ((cmd = it->next->cont) && !(set_fd_in(cm, cmd, &it)))
				return (0);
		if (it->next && !ft_strncmp(cmd->pipe, "|", 1))
			if ((cmd = it->next->cont) && !(set_fd_pipe(cm, cmd)))
				return (0);
		if (it)
			it = it->next;
	}
	return (1);
}
