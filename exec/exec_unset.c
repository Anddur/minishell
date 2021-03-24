/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:38:38 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/12 14:41:39 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_all	*g_all;

void		unset_var(char *var)
{
	ft_lstrm_if(&(g_all->ord_env_lst), var, ft_cmp_env, fake_free);
	ft_lstrm_if(&(g_all->env_lst), var, ft_cmp_env, del_env);
	ft_lstrm_if(&(g_all->ses_var), var, ft_cmp_env, del_env);
	free_env_matrix(g_all->env_matrix);
	g_all->env_matrix = 0;
}

void		exec_unset(t_cmd *cmd)
{
	char	**temp;
	int		i;

	temp = cmd->cmd;
	i = 1;
	if (!temp[1])
		return ;
	else
		while (temp[i])
		{
			unset_var(temp[i]);
			i++;
		}
}
