/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:03:39 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/14 09:10:13 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	compute_insert(char c)
{
	t_dclst	*new;

	if (g_all->sigint == 1)
		restore_input();
	if (c == '\n')
		while (g_all->clst->next && g_all->clst->next->c != '\n')
			compute_right_arrow();
	c == '\n' ? write(1, "\x1b[0J", 4) : 0;
	if (!(new = ft_dclst_new(c)))
		free_exit();
	ft_dclst_insert(&(g_all->clst), new);
	write(1, &c, 1);
	incr_pos();
	g_all->oldwpos = new->c == '\n' ? 1 : g_all->oldwpos + 1;
}

void	ft_putc(char c)
{
	t_dclst	*new;
	int		oldh;
	int		oldw;

	compute_insert(c);
	oldh = g_all->hpos;
	oldw = g_all->wpos;
	turn_back(oldw, oldh);
	write(1, "\x1b[0J", 4);
	new = g_all->clst;
	while (g_all->clst->next)
		compute_right_arrow_through();
	g_all->clst = new;
	turn_back(oldw, oldh);
	g_all->hpos = oldh;
	g_all->wpos = oldw;
}

void	compute_set_flag(void)
{
	t_dclst	*it;
	char	back;

	back = 0;
	it = get_head(g_all->clst);
	g_all->flag = 0;
	while (it)
	{
		set_flag(&(g_all->flag), it->c, back);
		back = back == '\\' && it->c == '\\' ? 0 : it->c;
		it = it->next;
	}
}

void	compute_delete(void)
{
	char	flag;

	flag = ft_is_in_charset(g_all->clst->prev->c, "\\\'\"") ?
		g_all->clst->prev->c : 0;
	ft_dclst_delete(&g_all->clst);
	decr_pos();
	flag ? compute_set_flag() : 0;
}

void	ft_delete(void)
{
	t_dclst *it;
	int		oldh;
	int		oldw;

	if (g_all->clst->prev == NULL || g_all->clst->prev->c == '\n')
	{
		write(1, "\a", 1);
		return ;
	}
	compute_delete();
	oldh = g_all->hpos;
	oldw = g_all->wpos;
	turn_back(oldw, oldh);
	write(1, "\x1b[0J", 4);
	it = g_all->clst;
	while (g_all->clst->next)
		compute_right_arrow_through();
	write(1, " ", 1);
	g_all->clst = it;
	turn_back(oldw, oldh);
	g_all->wpos = oldw;
	g_all->hpos = oldh;
}
