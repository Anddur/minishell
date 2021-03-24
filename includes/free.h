/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 10:15:50 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/05 17:55:34 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

# include "../libft/libft.h"

void	free_cmd(void *cmd);
void	free_cmd_matrix(void *cont);
void	free_env_matrix(char **env_matrix);
void	free_redirnpipe(void *cont);
void	fake_free(void *cont);
void	free_exit_arg(int arg);
void	free_baby(void);
void	free_exit(void);
#endif
