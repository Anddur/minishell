/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:42:07 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/10 19:12:26 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "../libft/libft.h"
# include "struct_def.h"

t_lst	*ft_freecmds(t_lst *ret);
int		ft_cmp_env(void *data, void *env);
char	**create_env_entry(char *line);
void	del_env(void *env);
int		ft_error(void);
void	env_error(void);
void	merror_split(t_lst *it);
void	ft_perror(const char *err);
void	merror_redirnpipe(t_lst *it);
char	set_syntax_err(void);
void	insert_env(char **env);
void	pars_env(char **env);
void	print_prompt(void);
void	set_user(void);
t_lst	*ft_split_in_lst(char *l, char c);
char	**ft_split_mod(char *l, char c);
t_lst	*ft_redirnpipe(char *cmd);
void	cmd_error(void);
int		read_input(char *line);
char	set_flag(char *flag, char c, char back);
void	exec_cmd(t_lst *cmd);
char	*ft_trimback(char *cmd);
char	*ft_trimquote(char *cmd);
void	ft_perror(const char *err);
int		ft_cmp_env(void *data, void *env);
int		ft_cmp_nodes_env(void *first, void *second);
void	pid_error(void);
void	dup_error(void);
void	pipe_error(void);
void	pars_line(char *line);
void	print_logo2(void);
void	print_logo(void);
void	print_exit(void);
t_lst	*free_cmd_list(t_lst *ret);
t_cmd	*create_cmd(char **cont);
t_lst	*add_cmd(t_lst **ret, char *begin, char *end, char check);
void	add_cmd_entry(char **cmd, char *cmd_entry);
void	set_cmd_entry(t_lst *ret, char **cmd);
int		max(int x, int y);
int		min(int x, int y);
#endif
