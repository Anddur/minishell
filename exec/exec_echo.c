/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 09:45:08 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/05 17:37:14 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_all	*g_all;

void	exec_echo(t_cmd *cmd_)
{
	int		i;
	char	*temp;
	char	**cmd;
	char	check;
	int		fd;

	i = 1;
	cmd = cmd_->cmd;
	fd = !ft_strcmp(cmd_->pipe, "|") ? 1 : cmd_->fout;
	temp = cmd[i];
	check = !ft_strcmp(temp, "-n") ? 1 : 0;
	check ? i++ : 0;
	while (cmd[i])
	{
		temp = cmd[i];
		ft_putstr_fd(temp, fd);
		if (cmd[i + 1])
			ft_putchar_fd(' ', fd);
		i++;
	}
	if (!check)
		ft_putchar_fd('\n', fd);
	g_all->last_exit = 0;
}
