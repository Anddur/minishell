/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 17:59:14 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/14 10:10:10 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H
# define HISTORY_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/errno.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <limits.h>
# include <dirent.h>
# include <string.h>
# include <curses.h>
# include <term.h>
# include <termios.h>
# include "struct_def.h"

void	read_input_(void);
void	init_term(void);
void	restore_term(void);
void	init_input(void);
void	restore_input(void);
void	parse_escape(void);
void	parse_input(char ch);
void	compute_left_arrow_through(void);
void	compute_left_arrow_mod(void);
void	compute_left_arrow(void);
void	compute_alt_left(void);
void	compute_right_arrow_delete(void);
void	compute_right_arrow_through(void);
void	compute_right_arrow_mod(void);
void	compute_right_arrow(void);
void	compute_alt_right(void);
void	compute_alt_arrow(void);
void	compute_esc_arrow(void);
void	compute_arrow(char ch);
void	compute_up_arrow(void);
void	compute_down_arrow(void);
void	restore_input(void);
void	ft_putc(char c);
void	clear_line(void);
void	ft_delete(void);
void	compute_paste(void);
void	dup_tmpclst(void);
void	compute_copy(void);
t_dclst	*first_newline(void);
void	compute_cut(void);
void	put_cmd(void);
void	compute_alt_up(void);
void	compute_alt_down(void);
void	compute_goend_mod(void);
void	compute_goend(void);
void	compute_gohome_mod(void);
void	compute_gohome(void);
void	goto_prev_line(void);
void	clear_line(void);
void	turn_back(int oldw, int oldh);
void	incr_pos(void);
void	incr_pos_mod(t_dclst *it);
void	decr_pos(void);
void	save_history(void);
void	get_history(void);
#endif
