/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:52:39 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/13 19:53:36 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_all *g_all;

void	fill_result(char *res, t_dclst *it)
{
	int		i;
	char	flag;
	char	back;

	i = 0;
	flag = 0;
	back = 0;
	while (it)
	{
		set_flag(&flag, it->c, back);
		back = it->c;
		if (it->next && it->next->c == '\n' && it->c == '\\' && !flag)
			it = it->next;
		else if (it->next && it->next->c == '\n' && it->c == '\\' &&
				flag == '\"')
			it = it->next;
		else
			res[i++] = it->c;
		it = it->next;
	}
}

char	*create_line(void)
{
	char	*res;
	t_dclst	*it;
	int		len;

	len = 1;
	it = g_all->clst;
	while (it && it->next && ++len)
		it = it->next;
	while (g_all->clst && g_all->clst->prev && len++)
		g_all->clst = g_all->clst->prev;
	if (!(res = ft_calloc(len + 1, sizeof(char))))
		free_exit();
	fill_result(res, g_all->clst);
	restore_term();
	return (res);
}

void	init_input(void)
{
	void *new;

	g_all->clst = 0;
	if (!(new = ft_dclst_new(' ')))
		free_exit();
	ft_dclst_insert(&(g_all->clst), new);
	if (g_all->hlst && !(g_all->tmphlst = ft_dupdlst(g_all->hlst,
		ft_dupdclst, ft_dclst_clear)))
		free_exit();
	if (!(ft_dlst_addfront(&g_all->tmphlst, ft_dlst_new(g_all->clst))))
		free_exit();
	g_all->ncwr = 0;
	g_all->cpos = g_all->llimit;
	g_all->wpos = 1;
	g_all->oldwpos = 1;
	g_all->hpos = 0;
	g_all->maxh = 0;
	g_all->sigint = 0;
	g_all->flag = 0;
	g_all->wshell = g_all->twshell;
	g_all->hshell = g_all->thshell;
}

void	init_reading(int *ch, char *back)
{
	*ch = 0;
	*back = 0;
}

void	read_input_(void)
{
	int		ch;
	char	back;

	init_reading(&ch, &back);
	init_term();
	init_input();
	while (ch != '\r' || g_all->flag ||
		(g_all->clst->prev && g_all->clst->prev->c == '\\'))
	{
		parse_input(ch);
		set_flag(&g_all->flag, ch, back);
		back = ch;
		read(0, &ch, 1);
	}
	if (g_all->maxh)
		compute_goend_mod();
	write(1, "\n", 1);
	if (g_all->tmphlst &&
		(get_head(g_all->tmphlst->cont) == get_head(g_all->clst)))
		g_all->clst = ft_dupdclst(get_head(g_all->tmphlst->cont));
	ft_dlst_clear(&g_all->tmphlst, ft_dclst_clear);
	if (g_all->sigint == 1 && !(g_all->sigint = 0))
		ft_dclst_clear(&g_all->clst);
	read_input(create_line());
}
