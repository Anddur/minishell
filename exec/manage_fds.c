/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_fds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:01:55 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/10 14:01:56 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	dup_fds(t_cmd *cm)
{
	if (dup2(cm->fin, STDIN_FILENO) != STDIN_FILENO ||
		dup2(cm->fout, STDOUT_FILENO) != STDOUT_FILENO)
		dup_error();
}

void	close_fds(t_lst *cmd)
{
	t_lst *it;
	t_cmd *cm;

	it = cmd;
	while (it)
	{
		cm = it->cont;
		if (cm->fin != 0)
			close(cm->fin);
		if (cm->fout != 1)
			close(cm->fout);
		it = it->next;
	}
}

int		ft_count_pipes(t_lst *cmd)
{
	t_lst	*it;
	int		i;

	it = cmd;
	i = 0;
	while (it)
	{
		if (ft_is_in_charset('|', ((t_cmd *)it->cont)->pipe))
			i++;
		it = it->next;
	}
	return (i);
}
