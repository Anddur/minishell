/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 10:40:48 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/14 12:32:05 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_all *g_all;

void	print_cmd_lst(void)
{
	t_lst	*it;
	t_lst	*it_cont;
	char	**cont;

	it = g_all->cmds;
	while (it)
	{
		it_cont = it->cont;
		while (it_cont)
		{
			cont = it_cont->cont;
			while (*cont)
				printf("%s", *cont++);
			printf("-");
			it_cont = it_cont->next;
		}
		printf("\n");
		it = it->next;
	}
}

void	set_shlvl(void)
{
	t_lst	*it;
	char	**shlvl;
	int		lvl;

	it = ft_lstfind(g_all->env_lst, "SHLVL", ft_strcmp_matrix);
	if (!it)
	{
		if (!(shlvl = ft_calloc(2, sizeof(char *))))
			env_error();
		if (!(shlvl[0] = ft_strdup("SHLVL")))
			env_error();
		if (!(shlvl[1] = ft_itoa(1)))
			env_error();
		insert_env(shlvl);
		return ;
	}
	shlvl = it->cont;
	lvl = ft_atoi(shlvl[1]);
	free(shlvl[1]);
	if (!(shlvl[1] = ft_itoa(lvl + 1)))
		env_error();
}

void	init_termcap(void)
{
	struct winsize	argp;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &argp);
	g_all->wshell = argp.ws_col;
	g_all->hshell = argp.ws_row;
	g_all->twshell = argp.ws_col;
	g_all->thshell = argp.ws_row;
}

int		main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	print_logo();
	if (!(g_all = ft_calloc(1, sizeof(t_all))))
		return (ft_error());
	pars_env(env);
	init_termcap();
	set_shlvl();
	set_user();
	get_history();
	while (1)
	{
		errno = 0;
		ft_lstclear(&g_all->temp_var, free);
		signal(SIGINT, sig_int);
		signal(SIGQUIT, sig_int);
		signal(SIGWINCH, resize_win);
		print_prompt();
		read_input_();
		if (!errno)
			exec();
	}
}
