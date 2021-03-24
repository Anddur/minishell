/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_def.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 11:18:49 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/11 14:49:10 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_DEF_H
# define STRUCT_DEF_H

# include "../libft/libft.h"
# include <limits.h>
# include <termios.h>

typedef struct	s_cmd
{
	char	**cmd;
	char	pipe[4];
	int		fin;
	int		fout;
}				t_cmd;

typedef struct	s_all
{
	char			**env_matrix;
	char			**bin_paths;
	char			*cmd_path;
	t_lst			*env_lst;
	t_lst			*ord_env_lst;
	t_lst			*ses_var;
	t_lst			*temp_var;
	t_lst			*cmds;
	t_dclst			*clst;
	t_dclst			*tmpclst;
	t_dlst			*hlst;
	t_dlst			*tmphlst;
	struct termios	old;
	struct termios	new;
	char			path[PATH_MAX];
	char			home[PATH_MAX];
	char			user[100];
	int				cpos;
	int				hpos;
	int				maxh;
	int				wpos;
	int				oldwpos;
	int				ncwr;
	int				llimit;
	int				pid;
	int				last_exit;
	char			flag;
	int				sigint;
	int				hshell;
	int				wshell;
	int				thshell;
	int				twshell;
}				t_all;

#endif
