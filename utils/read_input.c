/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:36:08 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/09 16:20:31 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_all	*g_all;

void	free_splitted_list(t_lst *it)
{
	t_lst *temp;

	if (it == g_all->cmds && !(g_all->cmds = 0))
	{
		free(it);
		return ;
	}
	temp = g_all->cmds;
	while (temp && temp->next && temp->next != it)
		temp = temp->next;
	ft_lstclear(&it, free);
	temp->next = 0;
	ft_lstclear(&g_all->cmds, free_redirnpipe);
}

void	redirnpipe_parse(void)
{
	t_lst	*it;
	char	*cont;

	it = g_all->cmds;
	while (it)
	{
		cont = it->cont;
		if (!(it->cont = ft_redirnpipe(it->cont)))
		{
			free(cont);
			errno == 12 ? merror_redirnpipe(it) : cmd_error();
			free_splitted_list(it);
			return ;
		}
		free(cont);
		it = it->next;
	}
}

char	check_syntax(const char *line)
{
	char	check;

	check = 0;
	while (*line)
	{
		while (ft_is_in_charset(*line, " \t"))
			line++;
		if (!*line)
			return (1);
		if (*line == ';' && !check)
			return (0);
		else if (*line == ';')
			check = 0;
		else
			check = 1;
		line++;
	}
	return (1);
}

char	first_parse(char *line)
{
	if (!check_syntax(line))
	{
		errno = -1;
		ft_perror("Syntax error near token ;");
		return (0);
	}
	if (!(g_all->cmds = ft_split_in_lst(line, ';')))
	{
		cmd_error();
		return (0);
	}
	if (!g_all->cmds)
		return (0);
	if (!((char *)g_all->cmds->cont)[0])
	{
		ft_freecmds(g_all->cmds);
		return (0);
	}
	return (1);
}

int		read_input(char *line)
{
	char	*temp;
	t_dlst	*new;

	errno = 0;
	temp = line;
	if (!(line = ft_strtrim(line, " \t")))
		env_error();
	free(temp);
	if (!first_parse(line) && (g_all->last_exit = errno))
		return (0);
	redirnpipe_parse();
	if (*line && !(new = ft_dlst_new(g_all->clst)))
		free_exit();
	while (g_all->hlst && g_all->hlst->prev)
		g_all->hlst = g_all->hlst->prev;
	*line ? ft_dlst_addfront(&g_all->hlst, new) : 0;
	*line ? 0 : ft_dclst_clear(&g_all->clst);
	g_all->clst = 0;
	free(line);
	return (1);
}
