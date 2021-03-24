/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:52:50 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/14 12:36:25 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_all	*g_all;

void	free_all(void)
{
	int i;

	i = 0;
	save_history();
	while (g_all->bin_paths && g_all->bin_paths[i])
		free(g_all->bin_paths[i++]);
	free(g_all->bin_paths);
	i = 0;
	while (g_all->env_matrix && g_all->env_matrix[i])
		free(g_all->env_matrix[i++]);
	free(g_all->env_matrix);
	free(g_all->cmd_path);
	ft_lstclear(&g_all->cmds, free_redirnpipe);
	ft_lstclear(&g_all->ord_env_lst, fake_free);
	ft_lstclear(&g_all->env_lst, del_env);
	ft_lstclear(&g_all->temp_var, free);
	ft_dlst_clear(&g_all->hlst, ft_dclst_clear);
}

void	free_baby(void)
{
	free_all();
	restore_term();
	if (errno && errno != 127)
		ft_error();
	exit(errno);
}

void	free_exit(void)
{
	free_all();
	restore_term();
	if (errno && errno != 127)
		ft_error();
	exit(errno);
}

void	free_exit_arg(int arg)
{
	free_all();
	restore_term();
	errno = arg;
	exit(errno);
}
