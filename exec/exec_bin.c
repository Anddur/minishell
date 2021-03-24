/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 10:20:44 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/11 19:56:13 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_temp_var_env(int i)
{
	t_lst *it;

	it = g_all->temp_var;
	while (it)
	{
		g_all->env_matrix[i++] = ft_trimquote(it->cont);
		it = it->next;
	}
}

void	generate_env_matrix(void)
{
	int		len;
	t_lst	*it;
	int		i;

	it = g_all->env_lst;
	i = 0;
	len = ft_lstlen(g_all->env_lst);
	if (!(g_all->env_matrix = ft_calloc(len + 1 +
		ft_lstlen(g_all->temp_var), sizeof(char *))))
		free_exit();
	while (i < len)
	{
		if (!((char **)it->cont)[1] && ++i)
			continue ;
		if (!(g_all->env_matrix[i] =
			ft_strjoin(ft_strjoin(((char **)it->cont)[0], "="),
			((char **)it->cont)[1])))
			free_exit();
		i++;
		it = it->next;
	}
	add_temp_var_env(i);
}

void	real_exec(char **cmd, int *i)
{
	char	*cmd_end;

	if (!(cmd_end = ft_strjoin("/", cmd[0])))
		free_exit();
	if (g_all->cmd_path)
		free(g_all->cmd_path);
	if (!(g_all->cmd_path = ft_strjoin(g_all->bin_paths[*i],
		cmd_end)))
	{
		free(cmd_end);
		free_exit();
	}
	free(cmd_end);
	execve(g_all->cmd_path, cmd, g_all->env_matrix);
	free(g_all->cmd_path);
	g_all->cmd_path = 0;
	(*i)++;
}

void	print_error_fd(const char *before, const char *error,
						const char *after)
{
	ft_putstr_fd(RED"", 2);
	ft_putstr_fd(before, 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd(after, 2);
	ft_putstr_fd(NRM"", 2);
}

int		exec_bin(t_cmd *cmd_)
{
	int		i;
	char	**cmd;

	i = 0;
	cmd = cmd_->cmd;
	if (!g_all->env_matrix)
		generate_env_matrix();
	ft_lstclear(&(g_all->temp_var), free);
	g_all->temp_var = 0;
	execve(cmd[0], cmd, g_all->env_matrix);
	if (!ft_find_var_by_key("PATH"))
		print_error_fd(cmd[0], ": ", "");
	if (!g_all->bin_paths &&
	!(g_all->bin_paths = ft_split(ft_find_var_by_key("PATH"), ':')))
		free_exit();
	while (g_all->bin_paths[i])
		real_exec(cmd, &i);
	errno = 127;
	g_all->last_exit = 127;
	print_error_fd("Error: Command ", cmd[0], " not found\n");
	return (errno);
}
