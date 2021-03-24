/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:01:37 by mcossu            #+#    #+#             */
/*   Updated: 2021/02/23 12:59:27 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst	*ft_lstnew(void *content)
{
	t_lst *res;

	if (!(res = (t_lst *)malloc(sizeof(t_lst))))
		return (0);
	res->cont = content;
	res->next = 0;
	return (res);
}
