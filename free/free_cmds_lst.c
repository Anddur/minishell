/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmds_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 10:15:31 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/03 11:59:34 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_cmd_matrix(void *cont)
{
	char	**cmd_matrix;
	int		i;

	cmd_matrix = cont;
	i = 0;
	while (cmd_matrix && cmd_matrix[i])
		free(cmd_matrix[i++]);
	free(cmd_matrix);
}

void	free_cmd(void *cmd_)
{
	t_cmd *cmd;

	cmd = cmd_;
	free_cmd_matrix(cmd->cmd);
	free(cmd_);
}

void	free_redirnpipe(void *cont)
{
	t_lst	*it;

	it = cont;
	ft_lstclear(&it, free_cmd);
}

void	free_env_matrix(char **env_matrix)
{
	int i;

	i = 0;
	while (env_matrix && env_matrix[i])
		free(env_matrix[i++]);
	free(env_matrix);
}

void	fake_free(void *cont)
{
	if (cont)
		return ;
	return ;
}
