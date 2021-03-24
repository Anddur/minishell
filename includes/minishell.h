/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 11:20:46 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/11 15:24:21 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/errno.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/ioctl.h>
# include <limits.h>
# include <dirent.h>
# include <string.h>
# include <curses.h>
# include <term.h>
# include <termios.h>
# include "utils.h"
# include "free.h"
# include "history.h"
# include "exec.h"
# include "sign.h"
# include "struct_def.h"
# include "../libft/libft.h"

# define NRM  "\x1B[0m"
# define BLK  "\x1B[30m"
# define RED  "\x1B[31m"
# define GRN  "\x1B[32m"
# define YEL  "\x1B[33m"
# define BLU  "\x1B[34m"
# define MAG  "\x1B[35m"
# define CYN  "\x1B[36m"
# define WHT  "\x1B[37m"

# define BRED  "\x1B[41m"
# define BGRN  "\x1B[42m"
# define BYEL  "\x1B[43m"
# define BBLU  "\x1B[44m"
# define BMAG  "\x1B[45m"
# define BCYN  "\x1B[46m"
# define BWHT  "\x1B[47m"

# define BBLUWHT "\x1B[44m\x1B[37m"
# define BGRNBLK "\x1B[42m\x1B[30m"

extern t_all	*g_all;

#endif
