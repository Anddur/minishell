/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_manage2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:25:22 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/12 16:30:24 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlst	*ft_dlst_addfront(t_dlst **lst, t_dlst *new)
{
	if (!lst)
		return (0);
	if (!*lst)
	{
		*lst = new;
		return (new);
	}
	(*lst)->prev = new;
	new->next = *lst;
	*lst = new;
	return (new);
}
