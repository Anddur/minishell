/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 09:45:26 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/02 12:00:11 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(int fd)
{
	t_lst	*it;

	it = g_all->env_lst;
	while (it)
	{
		if (((char **)it->cont)[1])
		{
			ft_putstr_fd(((char **)it->cont)[0], fd);
			ft_putchar_fd('=', fd);
			ft_putstr_fd(((char **)it->cont)[1], fd);
			ft_putchar_fd('\n', fd);
		}
		it = it->next;
	}
	errno = 0;
	g_all->last_exit = 0;
}

void	exec_env(t_cmd *cmd)
{
	print_env(cmd->fout);
}
