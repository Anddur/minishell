/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirnpipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 10:14:59 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/05 16:20:49 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lst	*add_rediopipe(t_lst **ret, t_lst *last, char **cmd)
{
	t_cmd	*cm;

	if (!last && *ret)
		return (0);
	if (!**cmd)
		return (last);
	if (!*ret)
	{
		if (!(*ret = ft_calloc(1, sizeof(t_lst))))
			return (0);
		if (!((*ret)->cont = ft_calloc(1, sizeof(t_cmd))))
		{
			free(*ret);
			return (0);
		}
		cm = (*ret)->cont;
		cm->fin = 0;
		cm->fout = 1;
		last = *ret;
	}
	set_cmd_entry(last, cmd);
	return (last);
}

void	init_redirnpipe(t_lst **ret, char *flag,
						t_lst **last, char *back)
{
	*ret = 0;
	*flag = 0;
	*last = 0;
	*back = 0;
}

char	*ft_get_end(char *cmd, char *flag, char *back)
{
	while (*cmd && ((!ft_is_in_charset(*cmd, "<>|") || *flag || *back == '\\')))
	{
		set_flag(flag, *(cmd), *back);
		*back = *cmd == '\\' && *back == '\\' ? 0 : *cmd;
		cmd++;
	}
	return (cmd);
}

t_lst	*ft_redirnpipe(char *cmd)
{
	t_lst	*ret;
	char	*begin;
	char	flag;
	t_lst	*last;
	char	back;

	init_redirnpipe(&ret, &flag, &last, &back);
	while (*cmd)
	{
		if (!ft_is_in_charset(*cmd, "<>|"))
		{
			begin = cmd;
			cmd = ft_get_end(cmd, &flag, &back);
			if (flag && (errno = 22))
				return (free_cmd_list(ret));
			if (!(last = add_rediopipe(&ret,
				add_cmd(&ret, begin, cmd, *cmd), &cmd)))
				return (free_cmd_list(ret));
			if (!*cmd)
				return (ret);
		}
		else if (!add_rediopipe(&ret, last, &cmd))
			return (free_cmd_list(ret));
	}
	return (ret);
}
