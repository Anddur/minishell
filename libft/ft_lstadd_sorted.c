/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_sorted.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:25:10 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/12 16:25:11 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_sorted(t_lst **head, t_lst *new,
						int (*cmp)(void *, void *))
{
	t_lst	*it;
	void	*temp;

	if (!head)
		return ;
	it = *head;
	*head = new;
	new->next = it;
	it = new;
	while (it->next)
	{
		if (cmp(it->cont, it->next->cont) > 0)
		{
			temp = it->cont;
			it->cont = it->next->cont;
			it->next->cont = temp;
			it = it->next;
		}
		else
			return ;
	}
}
