/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_mod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 18:42:07 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/12 14:36:26 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		count_word(char *l, char c)
{
	char	flag;
	int		count;
	char	back;

	count = 0;
	flag = 0;
	back = 0;
	while (*l)
	{
		if (*l != c)
		{
			count++;
			while (*l && (*l != c || flag || back == '\\'))
			{
				set_flag(&flag, *l, back);
				back = back == '\\' && *l == '\\' ? 0 : *l;
				l++;
			}
			if (!*l)
				return (count);
		}
		l++;
	}
	return (count);
}

static char		*end_of_word(char *l, char *flag, char c)
{
	char	back;

	back = 0;
	while (*l && (*l != c || *flag || back == '\\'))
	{
		set_flag(flag, *l, back);
		back = back == '\\' && *l == '\\' ? 0 : *l;
		l++;
	}
	return (l);
}

static char		*create_cont(char **l, char *flag, char c)
{
	char	*end;
	char	*ret;
	char	check;

	end = end_of_word(*l, flag, c);
	check = *end;
	*end = 0;
	if (!(ret = ft_strdup(*l)))
		return (0);
	*end = check;
	*l = end;
	return (ret);
}

char			**ft_split_mod(char *l, char c)
{
	char	flag;
	char	**res;
	int		i;

	i = count_word(l, c);
	flag = 0;
	if (!(res = ft_calloc((i + 2), sizeof(char *))))
		return (0);
	i = 0;
	while (*l)
	{
		if (*l != c)
		{
			if (!(res[i] = create_cont(&l, &flag, c)) || flag)
			{
				free_cmd_matrix(res);
				return (0);
			}
			if (!*l)
				return (res);
			i++;
		}
		l++;
	}
	return (res);
}
