/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 14:18:22 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/05 17:57:37 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_all	*g_all;

char	*ft_strchr_mod(char *str, char c)
{
	if (!str)
		return (0);
	while (*str && !ft_is_in_charset(*str, "\"\'"))
		if (*str++ == c)
			return (str--);
	return (0);
}

char	exec_buildin(t_lst *cmd)
{
	char	**cmd_matrix;

	cmd_matrix = ((t_cmd *)cmd->cont)->cmd;
	if (!ft_strcmp(cmd_matrix[0], "echo"))
		exec_echo(cmd->cont);
	else if (!ft_strcmp(cmd_matrix[0], "cd"))
		exec_cd(cmd_matrix);
	else if (!ft_strcmp(cmd_matrix[0], "pwd"))
		exec_pwd();
	else if (ft_strchr_mod(cmd_matrix[0], '='))
		exec_assign(cmd_matrix);
	else if (!ft_strcmp(cmd_matrix[0], "export"))
		exec_export(cmd->cont);
	else if (!ft_strcmp(cmd_matrix[0], "unset"))
		exec_unset(cmd->cont);
	else if (!ft_strcmp(cmd_matrix[0], "env"))
		exec_env(cmd->cont);
	else if (!ft_strcmp(cmd_matrix[0], "exit"))
		exec_exit(cmd_matrix);
	else
		return (0);
	return (1);
}
