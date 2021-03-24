/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_right_arrow.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:02:32 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/14 11:36:43 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	compute_right_arrow_mod(void)
{
	int	limit;

	if (g_all->clst->next && g_all->clst->next->c != '\n')
	{
		limit = g_all->hpos ? 0 : g_all->llimit;
		g_all->cpos++;
		write(1, &(g_all->clst->c), 1);
		if ((g_all->wpos + limit) == (g_all->wshell))
		{
			g_all->hpos++;
			g_all->wpos = 1;
			write(1, "\n", 1);
		}
		else
			g_all->wpos++;
		g_all->clst = g_all->clst->next;
	}
	else
		write(1, "\a", 1);
}

void	compute_right_arrow_delete(void)
{
	int	limit;

	if (g_all->clst->next)
	{
		limit = g_all->hpos ? 0 : g_all->llimit;
		g_all->cpos++;
		write(1, "  \0", 3);
		if ((g_all->wpos + limit) == (g_all->wshell) || g_all->clst->c == '\n')
		{
			g_all->hpos++;
			g_all->wpos = 1;
			write(1, "\x1b[E", 3);
		}
		else
			g_all->wpos++;
		g_all->clst = g_all->clst->next;
	}
	else
		write(1, "\a", 1);
}

void	compute_right_arrow(void)
{
	int	limit;

	if (g_all->clst->next && g_all->clst->next->c != '\n')
	{
		limit = g_all->hpos ? 0 : g_all->llimit;
		g_all->cpos++;
		write(1, &(g_all->clst->c), 1);
		if ((g_all->wpos + limit) == (g_all->wshell))
		{
			g_all->hpos++;
			g_all->wpos = 1;
			write(1, "\n", 1);
		}
		else
			g_all->wpos++;
		g_all->oldwpos = g_all->wpos - 1;
		g_all->clst = g_all->clst->next;
	}
	else
		write(1, "\a", 1);
}

void	compute_right_arrow_through(void)
{
	int	limit;

	if (g_all->clst->next)
	{
		limit = g_all->hpos ? 0 : g_all->llimit;
		g_all->cpos++;
		if ((g_all->wpos + limit) == (g_all->wshell) || g_all->clst->c == '\n')
		{
			g_all->hpos++;
			g_all->wpos = 1;
			g_all->clst->c != '\n' ? write(1, &(g_all->clst->c), 1) : 0;
			write(1, "\n", 1);
		}
		else
		{
			write(1, &(g_all->clst->c), 1);
			g_all->wpos++;
		}
		g_all->clst = g_all->clst->next;
	}
}

void	compute_alt_right(void)
{
	if (g_all->clst->next && g_all->clst->next->c == ' ' &&
		g_all->clst->c != ' ' && g_all->clst->c != '\n')
		compute_right_arrow();
	while (g_all->clst->c != ' ' && g_all->clst->next &&
			g_all->clst->next->c != '\n')
		compute_right_arrow();
	while (g_all->clst->c == ' ' && g_all->clst->next &&
			g_all->clst->next->c != '\n')
		compute_right_arrow();
}
