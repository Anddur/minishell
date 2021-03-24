/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_assign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:43:05 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/04 18:30:32 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_all	*g_all;

void	exec_assign(char **cmd_matrix)
{
	t_lst	*it;
	t_lst	*env;
	char	*temp;
	char	**env_entry;

	it = g_all->temp_var;
	(void)cmd_matrix;
	while (it)
	{
		temp = it->cont;
		env_entry = create_env_entry(temp);
		free(it->cont);
		it->cont = env_entry;
		g_all->temp_var = it->next;
		it->next = 0;
		if (!(env = ft_find_it_by_key(env_entry[0])))
			ft_lstadd_front(&g_all->ses_var, it);
		else
		{
			insert_env(env_entry);
			free(it);
		}
		it = g_all->temp_var;
	}
}
