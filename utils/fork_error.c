/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 09:46:43 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/02 09:46:45 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pid_error(void)
{
	free_exit();
}

void	dup_error(void)
{
	free_exit();
}

void	pipe_error(void)
{
	free_exit();
}
