/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 09:49:02 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/14 13:08:22 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	save_history(void)
{
	int		fd;
	t_dlst	*it;
	t_dclst	*cit;

	fd = open(".history", O_CREAT | O_TRUNC | O_WRONLY, 0755);
	write(fd, "\n@!\n", 4);
	it = g_all->hlst;
	if (!it)
		return ;
	while (it->prev)
		it = it->prev;
	while (it)
	{
		cit = get_head(it->cont);
		while (cit)
		{
			write(fd, &cit->c, 1);
			cit = cit->next;
		}
		write(fd, "\n@!\n", 4);
		it = it->next;
	}
	write(fd, "@?\n", 3);
	close(fd);
}

void	clear_history(void)
{
	t_dlst	*it;
	t_dclst	*cit;
	t_dclst	*temp;

	it = g_all->hlst;
	while (it)
	{
		cit = it->cont;
		while (cit->next->next)
			cit = cit->next;
		temp = cit->prev;
		if (cit->next)
			free(cit->next);
		if (cit)
			free(cit);
		temp->next = 0;
		it = it->next;
	}
}

void	compute_history(char *line, t_dclst **temp)
{
	int		i;

	if (!ft_strcmp(line, "@?"))
	{
		if (*temp)
			free(*temp);
		*temp = 0;
	}
	else if (!ft_strcmp(line, "@!"))
	{
		if (*temp)
			ft_dlst_insert(&g_all->hlst, ft_dlst_new(get_head(*temp)));
		*temp = ft_dclst_new(' ');
	}
	else if (*line)
	{
		i = 0;
		while (line[i])
		{
			ft_dclst_insert(temp, ft_dclst_new(line[i]));
			i++;
		}
		ft_dclst_insert(temp, ft_dclst_new('\n'));
	}
}

void	get_history(void)
{
	int		fd;
	t_dclst	*temp;
	char	*line;

	fd = open(".history", O_RDONLY, 0755);
	line = 0;
	temp = 0;
	while (get_next_line(fd, &line) > 0)
	{
		compute_history(line, &temp);
		free(line);
		line = 0;
	}
	printf("%s\n", line);
	free(line);
	free(temp);
	clear_history();
	close(fd);
}
