/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_crud.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:27:56 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/10 16:31:55 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_all *g_all;

void	compute_paste(void)
{
	t_dclst	*it;

	if (!g_all->tmpclst)
		return ;
	it = g_all->tmpclst;
	while (it)
	{
		ft_putc(it->c);
		it = it->next;
	}
	ft_dclst_clear(&g_all->tmpclst);
	g_all->tmpclst = 0;
}

void	compute_copy(void)
{
	t_dclst *it;

	ft_dclst_clear(&g_all->tmpclst);
	dup_tmpclst();
	it = g_all->tmpclst;
	while (it && it->next)
		it = it->next;
	it && it->c == ' ' ? it->prev->next = 0 : 0;
	it && it->c == ' ' ? free(it) : 0;
}

t_dclst	*first_newline(void)
{
	t_dclst *it;

	it = g_all->clst;
	while (it->next && it->c != '\n')
		it = it->next;
	return (it);
}
