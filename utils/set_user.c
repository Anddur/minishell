/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_user.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:20:16 by mcossu            #+#    #+#             */
/*   Updated: 2021/02/25 10:26:41 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_all	*g_all;

void	set_user(void)
{
	t_lst *user;

	user = ft_lstfind(g_all->env_lst, "USER", ft_cmp_env);
	if (user)
	{
		ft_strlcpy(g_all->user, ((char **)user->cont)[1], 100);
	}
	else
		ft_strlcpy(g_all->user, "root", 100);
}
