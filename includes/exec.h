/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 10:20:58 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/05 17:57:43 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "../libft/libft.h"
# include "struct_def.h"

void	exec(void);
int		ft_strcmp_matrix(void *data, void *cont);
t_lst	*ft_find_it_by_key(const char *key);
char	*ft_find_var_by_key(const char *key);
int		find_single_quote(const char *var, int i);
char	*compute_expand(char *var, int i);
char	*expand_var(char *var);
void	parse_cmd(t_lst *cmd);
void	exec_assign(char **cmd_matrix);
int		exec_bin(t_cmd *cmd);
int		exec_cd(char **cmd);
void	exec_echo(t_cmd *cmd);
void	exec_exit(char **cmd_matrix);
void	exec_env(t_cmd *cmd);
int		exec_pwd(void);
char	exec_buildin(t_lst *cmd);
void	exec_export(t_cmd *cmd);
void	exec_unset(t_cmd *cmd);
char	set_fd_out(t_cmd *cmd, t_cmd *file, t_lst **it);
char	set_fd_in(t_cmd *cmd, t_cmd *file, t_lst **it);
char	set_fd_pipe(t_cmd *cmdout, t_cmd *cmdin);
char	set_fds(t_lst *lst);
void	dup_fds(t_cmd *cm);
void	close_fds(t_lst *cmd);
char	parse_syntax(t_lst *cmd);
char	parse_syntax_cmds(void);
void	sub_vars(t_lst *cmd);
int		ft_count_pipes(t_lst *cmd);
#endif
