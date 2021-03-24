/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 09:43:45 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/05 18:28:49 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_all	*g_all;

void		ft_putstr_mod_fd(char *var, int fd)
{
	while (*var)
	{
		if (*var == '\"')
			ft_putchar_fd('\\', fd);
		ft_putchar_fd(*var++, fd);
	}
}

void		print_sort_env(int fd)
{
	t_lst	*it;

	it = g_all->ord_env_lst;
	while (it)
	{
		ft_putstr_fd("declare -x ", fd);
		ft_putstr_fd(((char **)it->cont)[0], fd);
		if (((char **)it->cont)[1])
		{
			ft_putchar_fd('=', fd);
			ft_putstr_fd("\"", fd);
			ft_putstr_mod_fd(((char **)it->cont)[1], fd);
			ft_putstr_fd("\"", fd);
		}
		ft_putchar_fd('\n', fd);
		it = it->next;
	}
}

void		pars_var(char *var)
{
	char	*last;
	char	**env;
	int		i;
	char	check;

	i = 0;
	if (!(env = ft_calloc(3, sizeof(char *))))
		env_error();
	while (var[i] && var[i] != '=')
		i++;
	last = var[i] ? &var[i + 1] : &var[i];
	check = var[i] ? 1 : 0;
	var[i] = 0;
	if (!(env[0] = ft_strdup(var)))
	{
		del_env(env);
		env_error();
	}
	if (check && !(env[1] = ft_strdup(last)))
	{
		del_env(env);
		env_error();
	}
	insert_env(env);
}

void		export_all(void)
{
	t_lst	*it;
	t_lst	*new;

	it = g_all->ses_var;
	while (it)
	{
		g_all->ses_var = it->next;
		it->next = 0;
		ft_lstadd_front(&(g_all->env_lst), it);
		if (!(new = ft_lstnew(it->cont)))
			free_exit();
		ft_lstadd_sorted(&(g_all->ord_env_lst), new, ft_cmp_nodes_env);
		it = g_all->ses_var;
	}
}

void		exec_export(t_cmd *cmd)
{
	char	**temp;
	int		i;
	int		fd;

	temp = cmd->cmd;
	i = 0;
	if (!temp[1])
	{
		export_all();
		if (!ft_strcmp(cmd->pipe, "|"))
			fd = 1;
		else
			fd = cmd->fout;
		print_sort_env(fd);
	}
	else
	{
		while (temp[++i])
			if (!strcmp(temp[i], "="))
				printf("Bad assignement\n");
			else
				pars_var(temp[i]);
	}
}
