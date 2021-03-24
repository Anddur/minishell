/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:24:38 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/12 17:50:10 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	incr_pos(void)
{
	int	limit;

	limit = g_all->hpos ? -1 : g_all->llimit - 1;
	g_all->cpos++;
	g_all->ncwr++;
	g_all->clst->prev && g_all->clst->prev->c == '\n' ?
			g_all->wpos = 1 : g_all->wpos++;
	g_all->wpos + limit == g_all->wshell ? g_all->hpos++ : 0;
	g_all->wpos + limit == g_all->wshell ? write(1, "\n", 1) : 0;
	g_all->wpos + limit == g_all->wshell ? g_all->maxh++ : 0;
	g_all->wpos + limit == g_all->wshell ? g_all->wpos = 1 : 0;
	g_all->clst->prev && g_all->clst->prev->c == '\n' ? g_all->hpos++ : 0;
	g_all->clst->prev && g_all->clst->prev->c == '\n' ? g_all->maxh++ : 0;
}

void	incr_pos_mod(t_dclst *it)
{
	int	limit;

	limit = g_all->hpos ? -1 : g_all->llimit - 1;
	g_all->cpos++;
	g_all->ncwr++;
	it && it->c == '\n' ?
			g_all->wpos = 1 : g_all->wpos++;
	it && it->c == '\n' ?
			write(1, " ", 1) : 0;
	g_all->wpos + limit == g_all->wshell ? g_all->hpos++ : 0;
	g_all->wpos + limit == g_all->wshell ? write(1, " ", 1) : 0;
	g_all->wpos + limit == g_all->wshell ? write(1, " \x1b[E", 4) : 0;
	g_all->wpos + limit == g_all->wshell ? g_all->wpos = 1 : 0;
	it && it->c == '\n' ? g_all->hpos++ : 0;
	g_all->oldwpos = g_all->wpos;
}

void	decr_pos(void)
{
	g_all->cpos--;
	g_all->ncwr--;
	g_all->wpos--;
	if (!g_all->wpos && g_all->hpos)
	{
		g_all->wpos = g_all->wshell;
		goto_prev_line();
	}
	g_all->oldwpos--;
}

void	clear_line(void)
{
	compute_gohome_mod();
	write(1, "\x1b[0J", 4);
}

void	turn_back(int oldw, int oldh)
{
	char	*temp;
	char	buff[30];
	int		limit;

	limit = !oldh ? g_all->llimit : 0;
	temp = ft_itoa(oldw - 1 + limit);
	write(1, "\r", 1);
	ft_strlcpy(buff, "\x1b[", 30);
	ft_strlcat(buff, temp, 30);
	ft_strlcat(buff, "C", 30);
	oldw - 1 + limit ? ft_putstr_fd(buff, 1) : 0;
	free(temp);
	if (!(g_all->hpos - oldh))
		return ;
	temp = ft_itoa(g_all->hpos - oldh);
	ft_strlcpy(buff, "\x1b[", 30);
	ft_strlcat(buff, temp, 30);
	ft_strlcat(buff, "A", 30);
	ft_putstr_fd(buff, 1);
	free(temp);
}
