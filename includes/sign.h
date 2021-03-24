/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sign.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:57:12 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/11 15:17:01 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGN_H
# define SIGN_H

# include "../libft/libft.h"

void	sig_int(int sig);
void	sig_eof(void);
void	resize_win(int sig);

#endif
