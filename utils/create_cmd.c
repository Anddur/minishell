/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:03:30 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/10 14:03:30 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lst	*free_cmd_list(t_lst *ret)
{
	ft_lstclear(&ret, free_cmd);
	return (0);
}

t_cmd	*create_cmd(char **cont)
{
	t_cmd	*cmd;

	if (!(cmd = ft_calloc(1, sizeof(t_cmd))))
	{
		free_cmd_matrix(cont);
		return (0);
	}
	cmd->cmd = cont;
	cmd->fin = STDIN_FILENO;
	cmd->fout = STDOUT_FILENO;
	return (cmd);
}

t_lst	*add_cmd(t_lst **ret, char *begin, char *end, char check)
{
	char	*trim;
	void	*cont;
	t_lst	*new;

	check ? *end = 0 : 0;
	if (!(trim = ft_strtrim(begin, " \t")))
		return (0);
	if (!(cont = ft_split_mod(trim, ' ')))
	{
		free(trim);
		return (0);
	}
	free(trim);
	if (!(cont = create_cmd(cont)))
		return (0);
	if (!(new = ft_lstnew(cont)))
	{
		free_cmd(cont);
		return (0);
	}
	*end = check;
	ft_lstadd_back(ret, new);
	return (new);
}

void	add_cmd_entry(char **cmd, char *cmd_entry)
{
	while (ft_is_in_charset(**cmd, " \t"))
		(*cmd)++;
	while (ft_is_in_charset(**cmd, "<>|"))
	{
		while (*cmd_entry)
			cmd_entry++;
		*(cmd_entry) = *((*cmd)++);
	}
}

void	set_cmd_entry(t_lst *ret, char **cmd)
{
	char	*cmd_entry;
	int		i;

	i = 0;
	cmd_entry = ((t_cmd *)ret->cont)->pipe;
	while (cmd_entry[i])
		i++;
	if (**cmd == '>' && *((*cmd) + 1) == '>' && ((*cmd)++))
	{
		cmd_entry[i] = '>';
		cmd_entry[i + 1] = '>';
		cmd_entry[i + 2] = 0;
	}
	else if (**cmd == '>')
		cmd_entry[i] = '>';
	else if (**cmd == '<')
		cmd_entry[i] = '<';
	else if (**cmd == '|')
		cmd_entry[i] = '|';
	if (**cmd)
		(*cmd)++;
	add_cmd_entry(cmd, cmd_entry);
}
