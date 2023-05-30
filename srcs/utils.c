/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 01:26:28 by cparras           #+#    #+#             */
/*   Updated: 2023/05/30 16:51:36 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	err_cmd(char *str, char *cmd, char *end)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(end, 2);
}

char	*check_path(char *cmd, char **ev)
{
	char	**paths;
	char	*path;
	char	*no_ex;
	int		i;

	i = -1;
	while (ft_strncmp(ev[++i], "PATH=", 5))
		;
	paths = ft_split(ev[i] + 5, ':');
	i = -1;
	while (paths[++i])
	{
		no_ex = ft_strjoin(paths[i], "/");
		path = ft_strjoin(no_ex, cmd);
		free(no_ex);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
	}
	err_cmd("pipex: ", cmd, ": command not found\n");
	return (NULL);
}

void	exectute_cmd(char *av, char **ev)
{
	int		i;
	char	*path;
	char	**cmd;

	i = -1;
	cmd = ft_split(av, ' ');
	path = check_path(cmd[0], ev);
	if (!path)
	{
		free_array(cmd);
		exit(2);
	}
	execve(path, cmd, ev);
}
