/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_homenend.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 11:45:46 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/14 11:45:49 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	compute_goend(void)
{
	while (g_all->clst->next && g_all->clst->next->c != '\n')
		compute_right_arrow();
}

void	compute_gohome(void)
{
	while (g_all->clst->prev && g_all->clst->prev->c != '\n')
		compute_left_arrow();
}

void	compute_gohome_mod(void)
{
	while (g_all->clst->prev)
		g_all->clst = g_all->clst->prev;
	compute_left_arrow_mod();
}

void	compute_goend_mod(void)
{
	int		i;
	char	*temp;
	char	buff[30];

	i = 0;
	while (g_all->clst->next)
	{
		i++;
		if (g_all->clst->next->c == '\n')
			i = 0;
		g_all->clst = g_all->clst->next;
	}
	write(1, "\r", 1);
	temp = ft_itoa(g_all->maxh - g_all->hpos);
	ft_strlcpy(buff, "\x1b[", 30);
	ft_strlcat(buff, temp, 30);
	ft_strlcat(buff, "B", 30);
	ft_putstr_fd(buff, 1);
	free(temp);
	temp = ft_itoa(i);
	ft_strlcpy(buff, "\x1b[", 30);
	ft_strlcat(buff, temp, 30);
	ft_strlcat(buff, "C", 30);
	ft_putstr_fd(buff, 1);
	free(temp);
}
