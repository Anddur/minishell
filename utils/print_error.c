/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 09:48:03 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/02 09:48:04 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_perror(const char *err)
{
	if (errno == -1)
		printf(RED"%s\n"NRM, err);
	else
		printf(RED"%s %s\n"NRM, err, strerror(errno));
}
