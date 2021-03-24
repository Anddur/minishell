/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 17:13:47 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/04 16:08:30 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_all	*g_all;

int		ft_strcmp_matrix(void *data, void *cont)
{
	char	*d;
	char	**c;
	int		i;

	d = data;
	c = cont;
	i = 0;
	if (!d && c && !c[0])
		return (0);
	if (!d)
		return (-*(c[0]));
	if (!c[0])
		return (*d);
	while (*d && (c[0][i]) && *d == (c[0][i]))
	{
		d++;
		i++;
	}
	return ((unsigned char)*d - (unsigned char)(c[0][i]));
}

char	*ft_find_var_by_key(const char *key)
{
	t_lst	*it;

	it = ft_lstfind(g_all->env_lst, (char *)key, ft_strcmp_matrix);
	if (it)
		return (((char **)it->cont)[1]);
	it = ft_lstfind(g_all->ses_var, (char *)key, ft_strcmp_matrix);
	if (it)
		return (((char **)it->cont)[1]);
	return (0);
}

t_lst	*ft_find_it_by_key(const char *key)
{
	t_lst	*it;

	it = ft_lstfind(g_all->env_lst, (char *)key, ft_strcmp_matrix);
	if (it)
		return (it);
	it = ft_lstfind(g_all->ses_var, (char *)key, ft_strcmp_matrix);
	if (it)
		return (it);
	return (0);
}
