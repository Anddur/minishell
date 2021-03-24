/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmp_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 09:49:42 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/02 09:49:44 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_cmp_env(void *data, void *env)
{
	char	*data_s;
	char	**env_s;
	size_t	data_l;
	size_t	env_l;

	data_s = data;
	env_s = env;
	data_l = ft_strlen(data_s);
	env_l = ft_strlen(env_s[0]);
	if (data_l != env_l)
		return (1);
	return (ft_strncmp(data_s, env_s[0], data_l));
}

int		ft_cmp_nodes_env(void *first, void *second)
{
	char	**env_first;
	char	**env_second;

	env_first = first;
	env_second = second;
	return (ft_strcmp(env_first[0], env_second[0]));
}
