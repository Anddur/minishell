/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trimquote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 09:47:54 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/05 17:07:35 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		find_real_len(char *cmd)
{
	int		len;
	char	flag;
	char	back;

	len = 0;
	flag = 0;
	back = 0;
	while (cmd && *cmd)
	{
		if (!set_flag(&flag, *cmd, back))
			len++;
		back = back == '\\' && *cmd == '\\' ? 0 : *cmd;
		cmd++;
	}
	return (len);
}

int		find_real_len_back(char *cmd)
{
	int		len;
	char	back;

	len = 0;
	back = 0;
	while (cmd && *cmd)
	{
		if (*cmd != '\\' || back == '\\')
			len++;
		back = back == '\\' && *cmd == '\\' ? 0 : *cmd;
		cmd++;
	}
	return (len);
}

char	*ft_trimback(char *cmd)
{
	int		len;
	char	*ret;
	int		i;
	char	back;

	len = find_real_len_back(cmd);
	i = 0;
	back = 0;
	if (!(ret = ft_calloc((len + 1), sizeof(char))))
		free_exit();
	while (cmd && *cmd)
	{
		if (*cmd != '\\' || back == '\\')
			ret[i++] = *cmd;
		back = back == '\\' && *cmd == '\\' ? 0 : *cmd;
		cmd++;
	}
	return (ret);
}

char	*ft_trimquote(char *cmd)
{
	int		len;
	char	*ret;
	char	flag;
	int		i;
	char	back;

	len = find_real_len(cmd);
	i = 0;
	flag = 0;
	back = 0;
	if (!(ret = ft_calloc((len + 1), sizeof(char))))
		free_exit();
	while (cmd && *cmd)
	{
		if (!set_flag(&flag, *cmd, back))
			if (*cmd != '\\' || back == '\\' || flag == '\'')
				ret[i++] = *cmd;
		back = back == '\\' && *cmd == '\\' ? 0 : *cmd;
		cmd++;
	}
	return (ret);
}
