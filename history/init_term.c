/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:23:57 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/09 16:13:43 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_all *g_all;

void	init_term(void)
{
	tcgetattr(STDIN_FILENO, &g_all->old);
	g_all->new = g_all->old;
	g_all->new.c_lflag &= ~(ICANON | ECHO | IEXTEN);
	g_all->new.c_iflag &= ~(ICRNL | IXON);
	g_all->new.c_cc[VMIN] = 1;
	g_all->new.c_cc[VTIME] = 0;
	if (tcsetattr(STDIN_FILENO, TCSANOW, &g_all->new) < 0)
		exit(errno);
}

void	restore_term(void)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &g_all->old);
}

void	restore_input(void)
{
	ft_dlst_clear(&g_all->tmphlst, ft_dclst_clear);
	g_all->clst = 0;
	g_all->sigint = 0;
	g_all->flag = 0;
	init_input();
}
