/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:56:28 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/14 10:34:34 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_all *g_all;

void	sig_int(int sig)
{
	if (sig == SIGINT)
	{
		(void)sig;
		if (!g_all->pid)
		{
			if (g_all->maxh)
				compute_goend_mod();
			write(STDOUT_FILENO, "\n", 1);
			print_prompt();
			g_all->last_exit = 1;
			g_all->sigint = 1;
			errno = 1;
		}
	}
	else if (sig == SIGQUIT)
	{
		(void)sig;
		if (g_all->pid)
		{
			write(STDOUT_FILENO, "quit\n", 5);
		}
	}
}

void	sig_eof(void)
{
	if (!g_all->pid && !g_all->ncwr)
	{
		errno = 0;
		g_all->last_exit = 0;
		write(STDOUT_FILENO, "exit\n", 5);
		print_exit();
		free_exit();
	}
	else if (g_all->ncwr > 0)
		write(STDOUT_FILENO, "\a", 1);
}

void	resize_win(int sig)
{
	struct winsize	argp;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &argp);
	(void)sig;
	g_all->twshell = argp.ws_col;
	g_all->thshell = argp.ws_row;
}
