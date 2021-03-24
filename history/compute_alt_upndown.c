/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_alt_upndown.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:27:27 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/14 11:44:37 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	go_to_prev_line(int *i, int *j)
{
	t_dclst	*it;
	char	found;

	found = 0;
	*i = 0;
	*j = 0;
	it = g_all->clst;
	while (it && it->prev)
	{
		found ? (*j)++ : (*i)++;
		if (it->c == '\n')
		{
			if (found)
				break ;
			found = 1;
		}
		it = it->prev;
	}
	!*j ? it = g_all->clst : 0;
	g_all->clst = it->c == '\n' ? it->next : it;
}

void	go_to_next_line(int *i, int *j)
{
	t_dclst	*it;

	it = g_all->clst;
	*i = 0;
	*j = 0;
	while (it->prev && it->prev->c != '\n')
	{
		it = it->prev;
		(*i)++;
	}
	it = g_all->clst;
	while (it && it->next)
	{
		if (it->c == '\n')
			break ;
		(*j)++;
		g_all->cpos++;
		it = it->next;
	}
	g_all->clst = it->c == '\n' ? it->next : it;
}

void	go_to_pos(int j)
{
	int		i;
	int		temp;

	(void)j;
	g_all->wpos = 1;
	i = -1;
	temp = g_all->oldwpos;
	if (!g_all->hpos)
		while (++i < g_all->llimit)
			write(1, "\x1b[C", 3);
	while (g_all->clst->next &&
			g_all->clst->next->c != '\n' && j--)
		compute_right_arrow();
	g_all->oldwpos = temp;
}

void	compute_alt_up(void)
{
	int		i;
	int		j;
	int		k;

	go_to_prev_line(&i, &j);
	!j ? write(1, "\a", 1) : 0;
	if (!j)
		return ;
	k = j / g_all->wshell + i / g_all->wshell;
	g_all->oldwpos = min(i--, g_all->oldwpos);
	if (!g_all->clst->prev && g_all->hpos)
	{
		k = g_all->oldwpos;
		compute_left_arrow_mod();
		g_all->oldwpos = k;
		while (g_all->oldwpos-- && g_all->clst->next->c != '\n')
			compute_right_arrow_mod();
		g_all->oldwpos = k;
		return ;
	}
	write(1, "\x1b[F", 3);
	while (g_all->hpos-- && k--)
		write(1, "\x1b[A", 3);
	go_to_pos(g_all->oldwpos);
}

void	compute_alt_down(void)
{
	t_dclst	*it;
	int		temp;
	int		i;
	int		j;
	int		k;

	it = g_all->clst;
	temp = g_all->hpos;
	g_all->hpos == g_all->maxh ? write(1, "\a", 1) : 0;
	if (g_all->hpos >= g_all->maxh)
		return ;
	go_to_next_line(&i, &j);
	g_all->oldwpos = max(i--, g_all->oldwpos);
	k = ((j + g_all->wpos + (!temp ? g_all->llimit : 0)) / g_all->wshell);
	if (!g_all->clst->next && g_all->hpos == temp)
	{
		g_all->clst = it;
		compute_goend();
		return ;
	}
	write(1, "\x1b[E", 3);
	while (++(g_all->hpos) && k--)
		write(1, "\x1b[B", 3);
	go_to_pos(g_all->oldwpos);
}
