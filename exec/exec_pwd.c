/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 09:45:40 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/02 09:45:41 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		exec_pwd(void)
{
	char	pwd[PATH_MAX];

	getcwd(pwd, PATH_MAX);
	printf("%s\n", pwd);
	errno = 0;
	g_all->last_exit = 0;
	return (1);
}
