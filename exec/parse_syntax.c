/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:02:20 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/10 14:02:20 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	parse_syntax(t_lst *cmd)
{
	char	**cmd_matrix;
	char	*prev;
	t_cmd	*cm;

	cm = cmd->cont;
	cmd_matrix = cm->cmd;
	if (!cmd_matrix)
		return (1);
	if (cmd_matrix[0][0] == '|')
		return (set_syntax_err());
	prev = cmd_matrix[0];
	cmd = cmd->next;
	while (cmd && cmd->next)
	{
		if (ft_strlen(prev) == ft_strlen(((char**)cmd->cont)[0]) &&
		!ft_strncmp(prev, ((char**)cmd->cont)[0], ft_strlen(prev)))
			return (set_syntax_err());
		prev = ((char**)cmd->cont)[0];
		cmd = cmd->next;
	}
	if (cmd && ft_is_in_charset(((char**)cmd->cont)[0][0], "<>|"))
		return (set_syntax_err());
	return (1);
}

char	parse_syntax_cmds(void)
{
	t_lst	*it;

	it = g_all->cmds;
	while (it)
	{
		if (!parse_syntax(it->cont))
		{
			ft_lstclear(&g_all->cmds, free_redirnpipe);
			g_all->last_exit = errno;
			return (0);
		}
		it = it->next;
	}
	return (1);
}

void	sub_vars(t_lst *cmd)
{
	char	**cont;

	while (cmd)
	{
		cont = ((t_cmd *)cmd->cont)->cmd;
		while (cont && *cont)
		{
			if (!(*cont = expand_var(*cont)))
				free_exit();
			cont++;
		}
		cmd = cmd->next;
	}
}
