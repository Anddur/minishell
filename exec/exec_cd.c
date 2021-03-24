/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 09:44:15 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/02 09:44:34 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_all	*g_all;

void	print_cd_error(const char *path)
{
	printf(RED"cd: %s:"NRM, path);
	errno = 20;
	ft_perror("");
}

void	set_pwd(const char *old_pwd)
{
	char	pwd_[PATH_MAX];
	char	**env_entry;

	getcwd(pwd_, PATH_MAX);
	if (!(env_entry = ft_calloc(3, sizeof(char *))))
		free_exit();
	if (!(env_entry[0] = ft_strdup("PWD")))
	{
		free_env_matrix(env_entry);
		free_exit();
	}
	if (!(env_entry[1] = ft_strdup(pwd_)))
	{
		free_env_matrix(env_entry);
		free_exit();
	}
	insert_env(env_entry);
	if (!(env_entry = ft_calloc(3, sizeof(char *))) ||
		!(env_entry[0] = ft_strdup("OLDPWD")) ||
		!(env_entry[1] = ft_strdup(old_pwd)))
	{
		free_env_matrix(env_entry);
		free_exit();
	}
	insert_env(env_entry);
}

int		exec_cd_home(const char *old_pwd)
{
	char	*home;
	int		res;

	home = ft_find_var_by_key("HOME");
	if (!home)
		chdir("/");
	home = ft_trimquote(home);
	res = chdir(home);
	if (res < 0)
		print_cd_error(home);
	else
		set_pwd(old_pwd);
	g_all->last_exit = errno;
	free(home);
	return (res);
}

int		exec_cd_path(const char *path_, const char *old_path)
{
	int		res;
	char	path[PATH_MAX];
	char	*home;

	if (path_[0] == '~')
	{
		home = ft_find_var_by_key("HOME");
		home = ft_trimquote(home);
		if (!home)
			chdir("/");
		ft_strlcat(path, home, ft_strlen(home) + 1);
		free(home);
		ft_strlcat(path, &path_[1], ft_strlen(path) + ft_strlen(path_));
		if ((res = chdir(path)) && res < 0)
			print_cd_error(path);
		else if (res >= 0)
			set_pwd(old_path);
		return (res);
	}
	if ((res = chdir(path_)) && res < 0)
		print_cd_error(path_);
	else
		set_pwd(old_path);
	g_all->last_exit = errno;
	return (res);
}

int		exec_cd(char **cmd)
{
	char	pwd[PATH_MAX];
	char	old_pwd[PATH_MAX];
	char	*temp;
	int		res;

	temp = cmd[1];
	getcwd(old_pwd, PATH_MAX);
	if (!temp)
		return (exec_cd_home(old_pwd));
	cmd[1] = ft_trimquote(cmd[1]);
	free(temp);
	if (ft_is_in_charset(cmd[1][0], "~/"))
		return (exec_cd_path(cmd[1], old_pwd));
	getcwd(pwd, PATH_MAX);
	ft_strlcat(pwd, "/", ft_strlen(pwd) + 2);
	ft_strlcat(pwd, cmd[1], ft_strlen(pwd) + ft_strlen(cmd[1]) + 1);
	res = chdir(pwd);
	if (res < 0)
		print_cd_error(cmd[1]);
	else
		set_pwd(old_pwd);
	g_all->last_exit = errno;
	return (res);
}
