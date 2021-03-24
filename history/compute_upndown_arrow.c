/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_upndown_arrow.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:03:10 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/10 16:13:31 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	put_cmd(void)
{
	t_dclst *it;

	!g_all->sigint ? clear_line() : 0;
	g_all->sigint = 0;
	g_all->clst = get_head(g_all->tmphlst->cont);
	g_all->wpos = 1;
	g_all->hpos = 0;
	g_all->maxh = 0;
	it = g_all->clst;
	if (!(g_all->clst = ft_dclst_new(' ')))
		free_exit();
	g_all->cpos = g_all->llimit;
	g_all->tmphlst->cont = g_all->clst;
	g_all->ncwr = 0;
	while (it->next)
	{
		ft_putc(it->c);
		it = it->next;
	}
	ft_dclst_clear(&it);
}

void	compute_up_arrow(void)
{
	if (g_all->sigint)
	{
		ft_dlst_clear(&g_all->tmphlst, ft_dclst_clear);
		g_all->clst = 0;
		init_input();
	}
	if (!g_all->tmphlst || !g_all->tmphlst->next)
	{
		write(1, "\a", 1);
		return ;
	}
	g_all->tmphlst = g_all->tmphlst->next;
	put_cmd();
}

void	compute_down_arrow(void)
{
	if (g_all->sigint)
	{
		ft_dlst_clear(&g_all->tmphlst, ft_dclst_clear);
		g_all->clst = 0;
		init_input();
	}
	if (!g_all->tmphlst || !g_all->tmphlst->prev)
	{
		write(1, "\a", 1);
		return ;
	}
	g_all->tmphlst = g_all->tmphlst->prev;
	put_cmd();
}
