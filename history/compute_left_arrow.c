/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_left_arrow.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:02:36 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/14 11:36:36 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	goto_prev_line(void)
{
	char	buff[30];
	char	*temp;

	if (!(temp = ft_itoa(g_all->wshell - 1)))
		free_exit();
	write(1, "\r", 1);
	write(1, "\x1b[A", 3);
	ft_strlcpy(buff, "\033[", 30);
	ft_strlcat(buff, temp, 30);
	ft_strlcat(buff, "C", 30);
	write(1, buff, ft_strlen(buff));
	free(temp);
}

void	compute_left_arrow_mod(void)
{
	char	*temp;
	char	buff[30];

	write(1, "\r", 1);
	while (g_all->hpos && g_all->hpos-- > 0)
		write(1, "\x1b[A", 3);
	if (!(temp = ft_itoa(g_all->llimit)))
		free_exit();
	ft_strlcpy(buff, "\x1b[", 30);
	ft_strlcat(buff, temp, 30);
	ft_strlcat(buff, "C", 30);
	ft_putstr_fd(buff, 1);
	g_all->wpos = 1;
	g_all->oldwpos = 1;
	g_all->hpos = 0;
	free(temp);
}

void	compute_left_arrow(void)
{
	if (g_all->clst->prev && g_all->clst->prev->c != '\n')
	{
		g_all->cpos--;
		g_all->wpos--;
		g_all->clst = g_all->clst->prev;
		if (g_all->wpos <= 0 && g_all->hpos)
		{
			goto_prev_line();
			g_all->hpos--;
			g_all->wpos = g_all->hpos ? g_all->wshell :
				g_all->wshell - g_all->llimit;
		}
		else if (g_all->wpos)
			write(1, "\b", 1);
		g_all->oldwpos = g_all->wpos - 1;
	}
	else
		write(1, "\a", 1);
}

void	compute_left_arrow_through(void)
{
	if (g_all->clst->prev)
	{
		g_all->cpos--;
		g_all->wpos--;
		g_all->clst = g_all->clst->prev;
		if (g_all->wpos <= 0 && g_all->hpos)
		{
			goto_prev_line();
			g_all->hpos--;
			g_all->wpos = g_all->hpos ? g_all->wshell :
				g_all->wshell - g_all->llimit;
		}
		else if (g_all->wpos)
			write(1, "\b", 1);
	}
	else
		write(1, "\a", 1);
}

void	compute_alt_left(void)
{
	if (g_all->clst->prev && g_all->clst->prev->c == ' ' &&
		g_all->clst->c != ' ')
		compute_left_arrow();
	while ((g_all->clst->c == ' ' && g_all->clst->prev &&
			g_all->clst->prev->c != '\n'))
		compute_left_arrow();
	while ((g_all->clst->c != ' ' && g_all->clst->prev &&
		g_all->clst->prev->c != '\n'))
		compute_left_arrow();
	if (g_all->clst->prev && g_all->clst->next && g_all->clst->prev->c != '\n')
		compute_right_arrow();
}
