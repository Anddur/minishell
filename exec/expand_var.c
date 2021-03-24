/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 11:24:59 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/12 18:21:54 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		find_single_quote(const char *var, int i)
{
	while (var[i] != '\'')
		i++;
	return (i + 1);
}

char	*expand(char *var, char flag, int i, int j)
{
	char	*value;
	char	*begin;
	char	*end;
	char	*res;

	if (var[i] == '?')
	{
		value = ft_itoa(g_all->last_exit);
		j = i + 1;
	}
	else
		value = ft_find_var_by_key(&var[i]);
	var[j] = var[i] == '?' ? var[j] : flag;
	begin = var;
	end = &var[j];
	if (!(res = malloc(ft_strlen(value) + ft_strlen(begin) +
		ft_strlen(end) + 1)))
		free_exit();
	ft_strlcpy(res, begin, ft_strlen(begin) + 1);
	ft_strlcat(res, value, ft_strlen(res) + ft_strlen(value) + 1);
	ft_strlcat(res, end, ft_strlen(res) + ft_strlen(end) + 1);
	free(var);
	return (res);
}

char	*compute_expand(char *var, int i)
{
	int		j;
	char	check;

	var[i++] = 0;
	j = i;
	while (var[j] && !ft_is_in_charset(var[j], " \t\"\'$"))
		j++;
	check = var[j];
	var[j] = 0;
	var = expand(var, check, i, j);
	return (var);
}

char	*expand_var(char *var)
{
	int		i;
	char	flag;
	char	back;

	i = 0;
	flag = 1;
	back = 0;
	while (var[i])
	{
		if (var[i] == '\"' && back != '\\' && ++i)
			flag *= -1;
		else if (var[i] == '\'' && back != '\\' && flag > 0)
			i = find_single_quote(var, i + 1);
		else if (var[i] == '$' && back != '\\')
			var = compute_expand(var, i);
		else if (var[i])
			i++;
		back = back == '\\' && var[i - 1] == '\\' ? 0 : var[i - 1];
	}
	return (var);
}
