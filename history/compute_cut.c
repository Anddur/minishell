/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_cut.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:24:34 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/12 16:24:35 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clear_cut(t_dclst *it)
{
	while (g_all->clst->prev && g_all->clst->prev != it->prev)
		ft_delete();
}

int		delete_dclst(t_dclst **lst)
{
	t_dclst	*it;
	t_dclst	*temp;
	t_dclst	*temp1;
	int		i;

	i = 0;
	if (!*lst)
		return (0);
	it = *lst;
	temp1 = (*lst)->prev;
	temp1->next = 0;
	while (it->next && ++i)
	{
		temp = it;
		it = it->next;
		free(temp);
	}
	if (it->c == ' ')
	{
		temp1->next = it;
		it->prev = temp1;
	}
	else
		free(it);
	return (i);
}

void	real_cut(void)
{
	t_dclst	*temp;
	t_dclst	*it;

	it = g_all->tmpclst;
	while (it && it->next)
		it = it->next;
	it && it->c == ' ' ? it->prev->next = 0 : 0;
	it && it->c == ' ' ? free(it) : 0;
	it = g_all->clst;
	temp = first_newline();
	while (g_all->clst != temp)
		compute_right_arrow_through();
	clear_cut(it);
}

void	dup_tmpclst(void)
{
	t_dclst	*temp;

	temp = first_newline();
	temp ? temp->prev->next = 0 : 0;
	g_all->tmpclst = ft_dupdclst_partial(g_all->clst);
	temp ? temp->prev->next = temp : 0;
}

void	compute_cut(void)
{
	ft_dclst_clear(&g_all->tmpclst);
	if (!g_all->ncwr || !g_all->clst->next || g_all->clst->next->c == '\n')
	{
		write(1, "\a", 1);
		return ;
	}
	dup_tmpclst();
	real_cut();
}
