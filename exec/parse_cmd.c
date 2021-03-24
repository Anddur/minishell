/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 11:29:12 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/05 17:56:09 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	there_is_equal(char *cmd)
{
	char	*cmd_;
	t_lst	*new;

	if (!cmd)
		return (0);
	cmd_ = cmd;
	if (g_all->env_matrix)
		free_env_matrix(g_all->env_matrix);
	g_all->env_matrix = 0;
	while (*cmd && *cmd != '=')
		if (ft_is_in_charset(*cmd++, "\'\""))
			return (0);
	if (*cmd == '=')
	{
		if (!(new = ft_lstnew(ft_strdup(cmd_))))
			free_exit();
		ft_lstadd_front(&g_all->temp_var, new);
		return (1);
	}
	return (0);
}

void	shift_matrix(char **matrix, int i)
{
	int		j;

	j = 0;
	while (j < i)
		free(matrix[j++]);
	j = 0;
	while (matrix[i])
		matrix[j++] = matrix[i++];
	while (j < i)
		matrix[j++] = 0;
}

char	*ft_trim_cmd(char *cmd)
{
	char	*temp;

	temp = cmd;
	if (!(cmd = ft_trimquote(cmd)))
		free_exit();
	free(temp);
	return (cmd);
}

void	parse_single_cmd(t_lst *cmd)
{
	char		**cmd_matrix;
	int			i;

	i = 0;
	cmd_matrix = ((t_cmd *)cmd->cont)->cmd;
	if (!cmd_matrix)
		return ;
	while (there_is_equal(cmd_matrix[i]))
		i++;
	if (i > 0 && cmd_matrix[i] != 0)
		shift_matrix(cmd_matrix, i);
	else if (i > 0)
		return ;
	if (ft_strchr(cmd_matrix[0], '='))
		return ;
	i = -1;
	while (cmd_matrix[++i])
		if (!(cmd_matrix[i] = ft_trim_cmd(cmd_matrix[i])))
			free_exit();
}

void	parse_cmd(t_lst *cmd)
{
	while (cmd)
	{
		parse_single_cmd(cmd);
		cmd = cmd->next;
	}
}
