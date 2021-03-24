/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 10:15:13 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/05 15:43:14 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			max(int x, int y)
{
	return (x > y ? x : y);
}

int			min(int x, int y)
{
	return (x < y ? x : y);
}

char		set_flag(char *flag, char c, char back)
{
	if (c == '\'' && !*flag && back != '\\')
		*flag = c;
	else if (c == '\"' && !*flag && back != '\\')
		*flag = c;
	else if (back != '\\' && c == '\"' && c == *flag)
		*flag = 0;
	else if (c == '\'' && c == *flag)
		*flag = 0;
	else
		return (0);
	return (1);
}
