/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:02:44 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/14 10:39:48 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_escape(void)
{
	char		ch;
	char		found;

	read(0, &ch, 1);
	found = 0;
	if (ch == 'c' && (found = 1))
		compute_alt_right();
	else if (ch == 'd' && (found = 1))
		compute_alt_left();
	else if (ch == 'a' && (found = 1))
		compute_alt_up();
	else if (ch == 'b' && (found = 1))
		compute_alt_down();
	if (found)
		return ;
	read(0, &ch, 1);
	if (ch == '1')
		compute_esc_arrow();
	else if (ch == 72)
		compute_gohome();
	else if (ch == 70)
		compute_goend();
	else
		compute_arrow(ch);
}

void	parse_input(char ch)
{
	if (ch == '\t')
		return ;
	if (ch == '\004')
		sig_eof();
	else if (ch == 127)
		ft_delete();
	else if (ch == '\x1b')
		parse_escape();
	else if (ch == 24)
		compute_cut();
	else if (ch == 11)
		compute_copy();
	else if (ch == 16)
		compute_paste();
	else if (ch == '\r' && !g_all->sigint)
		ft_putc('\n');
	else if (ch == '\r' && g_all->sigint)
		restore_input();
	else if (ch < 32)
		return ;
	else if (ch)
		ft_putc(ch);
}
