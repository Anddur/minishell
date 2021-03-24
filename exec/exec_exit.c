/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 09:45:34 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/10 19:16:27 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_all	*g_all;

void	exec_exit(char **cmd_matrix)
{
	int	i;

	i = 0;
	if (cmd_matrix[1])
	{
		while (ft_isdigit(cmd_matrix[1][i]))
			i++;
		if (cmd_matrix[1][i])
		{
			printf(RED"exit: %s: numeric argument required\n"NRM,
				cmd_matrix[1]);
			errno = 255;
		}
		else
			errno = ft_atoi(cmd_matrix[1]) % 256;
	}
	else
		errno = g_all->last_exit;
	print_exit();
	free_exit_arg(errno);
}
