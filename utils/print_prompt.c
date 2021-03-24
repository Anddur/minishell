/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:03:18 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/10 17:12:07 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_all	*g_all;

void	print_prompt(void)
{
	int		i;
	int		path_l;

	i = 0;
	path_l = 0;
	ft_putstr_fd(BGRNBLK, 1);
	g_all->llimit = ft_putstr_fd("minishell", 1);
	ft_putstr_fd(NRM, 1);
	getcwd(g_all->path, PATH_MAX);
	while (g_all->path[i])
	{
		if (g_all->path[i] == '/')
			path_l = i + 1;
		i++;
	}
	ft_putstr_fd(GRN, 1);
	write(1, ":", 2);
	g_all->llimit += ft_putstr_fd(&(g_all->path[path_l]), 1);
	write(1, " ", 1);
	g_all->llimit += ft_putstr_fd(g_all->user, 1);
	write(1, "$", 2);
	write(1, " ", 1);
	g_all->llimit += 4;
	g_all->cpos = g_all->llimit;
	ft_putstr_fd(NRM, 1);
}
