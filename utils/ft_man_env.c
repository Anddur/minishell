/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_man_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:41:41 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/04 18:36:27 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_all	*g_all;

void		del_env(void *env)
{
	char **env_s;

	env_s = env;
	if (env_s)
	{
		free(env_s[0]);
		free(env_s[1]);
		free(env_s);
	}
}

void		insert_env(char **env)
{
	t_lst *new;

	if ((new = ft_find_it_by_key(env[0])))
	{
		free(((char **)new->cont)[1]);
		((char **)new->cont)[1] = ft_trimquote(env[1]);
		free_env_matrix(env);
		return ;
	}
	if (!(new = ft_lstnew(env)))
		env_error();
	ft_lstadd_front(&(g_all->env_lst), new);
	if (!(new = ft_lstnew(env)))
		env_error();
	ft_lstadd_sorted(&g_all->ord_env_lst, new, ft_cmp_nodes_env);
	free_env_matrix(g_all->env_matrix);
	g_all->env_matrix = 0;
}

char		**create_env_entry(char *line)
{
	char	*last;
	char	**env;
	int		i;
	char	check;

	i = 0;
	if (!(env = ft_calloc(3, sizeof(char *))))
		env_error();
	while (line[i] && line[i] != '=')
		i++;
	last = line[i] ? &line[i + 1] : &line[i];
	check = line[i] ? 1 : 0;
	line[i] = 0;
	if (!(env[0] = ft_strdup(line)))
	{
		del_env(env);
		env_error();
	}
	if (check && !(env[1] = ft_strdup(last)))
	{
		del_env(env);
		env_error();
	}
	return (env);
}

void		pars_line(char *line)
{
	char	**env;

	env = create_env_entry(line);
	free(line);
	insert_env(env);
}

void		pars_env(char **env)
{
	int		i;
	char	*line;
	t_lst	*it;
	t_lst	*temp;

	i = 0;
	while (env[i])
	{
		if (!(line = ft_strdup(env[i])))
			env_error();
		pars_line(line);
		i++;
	}
	if (!i)
		return ;
	it = g_all->env_lst->next;
	g_all->env_lst->next = 0;
	while (it)
	{
		temp = it->next;
		ft_lstadd_front(&g_all->env_lst, it);
		it = temp;
	}
}
