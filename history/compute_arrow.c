/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_arrow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:02:10 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/10 14:02:10 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	compute_alt_arrow(void)
{
	char ch;

	read(0, &ch, 1);
	if (ch == 'D')
		compute_alt_left();
	else if (ch == 'C')
		compute_alt_right();
	else if (ch == 'A')
		compute_alt_up();
	else if (ch == 'B')
		compute_alt_down();
}

void	compute_esc_arrow(void)
{
	char ch;

	read(0, &ch, 1);
	read(0, &ch, 1);
	if (ch == '3')
		compute_alt_arrow();
	else
		read(0, &ch, 1);
}

void	compute_arrow(char ch)
{
	if (ch == 'D')
		compute_left_arrow();
	else if (ch == 'C')
		compute_right_arrow();
	else if (ch == 'A')
		compute_up_arrow();
	else if (ch == 'B')
		compute_down_arrow();
}
