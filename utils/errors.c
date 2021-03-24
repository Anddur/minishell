/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 12:40:50 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/04 15:15:24 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_all	*g_all;

int		ft_error(void)
{
	printf(RED"%s\n"NRM, strerror(errno));
	exit(errno);
	return (errno);
}

void	env_error(void)
{
	ft_lstclear(&(g_all->env_lst), del_env);
	ft_lstclear(&(g_all->temp_var), free);
	ft_error();
}

void	cmd_error(void)
{
	if (errno == 22)
	{
		errno = 22;
		printf(RED"Error: Quote not closed\n"NRM);
		return ;
	}
	if (errno)
		printf(RED"%s\n"NRM, strerror(errno));
	g_all->last_exit = errno;
	if (errno == 12)
		exit(1);
}

void	merror_split(t_lst *it)
{
	t_lst *temp;

	while (g_all->cmds != it)
	{
		temp = g_all->cmds;
		g_all->cmds = temp->next;
		ft_lstdelone(temp, free_cmd_matrix);
	}
	ft_lstclear(&(g_all->cmds), free);
	env_error();
}

void	merror_redirnpipe(t_lst *it)
{
	t_lst *temp;

	while (g_all->cmds != it)
	{
		temp = g_all->cmds;
		g_all->cmds = temp->next;
		ft_lstdelone(temp, free_redirnpipe);
	}
	ft_lstclear(&(g_all->cmds), free);
	env_error();
}
