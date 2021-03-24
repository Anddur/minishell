/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:46:29 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/05 15:37:41 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lst			*ft_freecmds(t_lst *ret)
{
	ft_lstclear(&ret, free);
	return (0);
}

static t_lst	*add_cmd_lst(t_lst **ret, char *begin, char *end, char check)
{
	char	*trim;
	t_lst	*new;

	check = *end ? 1 : 0;
	*end = 0;
	if (!(trim = ft_strtrim(begin, " \t")))
		return (0);
	if (!(new = ft_lstnew(trim)))
	{
		free(trim);
		return (0);
	}
	ft_lstadd_back(ret, new);
	check ? *end = ';' : 0;
	return (*ret);
}

t_lst			*return_split(t_lst *ret, char flag)
{
	if (flag)
		errno = 22;
	if (flag)
		return (ft_freecmds(ret));
	return (ret);
}

void			init_split(char *flag, t_lst **ret, char *back)
{
	*flag = 0;
	*ret = 0;
	*back = 0;
}

t_lst			*ft_split_in_lst(char *l, char c)
{
	char	flag;
	t_lst	*ret;
	char	*start;
	char	back;

	init_split(&flag, &ret, &back);
	while (*l)
	{
		if (*l != c && (start = l))
		{
			while (*l && (*l != c || flag))
			{
				set_flag(&flag, *l, back);
				back = back == '\\' && *l == '\\' ? 0 : *l;
				l++;
			}
			if (!add_cmd_lst(&ret, start, l, 0))
				return (ft_freecmds(ret));
			if (!*l)
				return (ret);
		}
		l++;
	}
	return (return_split(ret, flag));
}
