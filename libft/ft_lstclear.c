/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:54:11 by mcossu            #+#    #+#             */
/*   Updated: 2021/01/26 14:41:26 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_lst **lst, void (*del)(void*))
{
	t_lst *temp;
	t_lst *iter;

	if (!lst)
		return ;
	iter = *lst;
	while (iter)
	{
		temp = iter->next;
		ft_lstdelone(iter, del);
		iter = temp;
	}
	*lst = 0;
}
