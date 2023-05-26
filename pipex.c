/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:53:31 by romaurel          #+#    #+#             */
/*   Updated: 2023/05/26 17:53:23 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*cpy_s1;
	unsigned char	*cpy_s2;

	i = 0;
	cpy_s1 = (unsigned char *)s1;
	cpy_s2 = (unsigned char *)s2;
	while (cpy_s1[i] && cpy_s2[i] && i < n)
	{
		if (cpy_s1[i] != cpy_s2[i])
			return (cpy_s1[i] - cpy_s2[i]);
		i++;
	}
	if (i == n)
		return (0);
	return (cpy_s1[i] - cpy_s2[i]);
}

static void	ft_error(char *str)
{
	int			i;

	i = -1;
	while (str[++i])
		;
	write(2, str, i);
	exit(EXIT_FAILURE);
}

void	open_files(char **av, int fd[2])
{
	fd[0] = open(av[1], O_RDONLY);
	if (fd[0] == -1)
		ft_error("Error: file1 doesn't exist\n");
	fd[1] = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd[1] == -1)
		ft_error("Error: file2 doesn't exist\n");
}

void	pipe_cmd(char **av, char **env, int fd[2])
{
	int		pid;
	int		status;
	t_pipex	*p;

	get_path(p, av[2]);
	pid = fork();
	if (pid == -1)
		ft_error("Error: fork failed\n");
	if (pid == 0)
	{
		dup2(fd[0], 0);
		dup2(fd[1], 1);
		close(fd[0]);
		close(fd[1]);
		execve(p->path, av + 2, env);
		ft_error("Error: execve failed\n");
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dst;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	dst = malloc(sizeof(char) * (i + j + 1));
	if (!dst)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		dst[i] = s1[i];
	while (s2[++j])
		dst[i + j] = s2[j];
	dst[i + j] = '\0';
	free(s1);
	return (dst);
}

void	get_path(t_pipex *p, char *current)
{
	int		i;
	char	**uwu;

	while (p->env[i])
	{
		if (ft_strncmp(p->env[i], "PATH=", 5) == 0)
			uwu = ft_split(p->env[i] + 5, ':');
		i++;
	}
	i = 0;
	while (uwu[i])
	{
		p->path = ft_strjoin(uwu[i], "/");
		p->path = ft_strjoin(p->path, current);
		if (!access(p->path, X_OK))
		{
			free(uwu);
			return ;
		}
		free(p->path);
		i++;
	}	
}

int	pipex(int ac, char **av, char **env)
{
	int	fd[2];
	// int	;
	if (ac < 5)
		ft_error("usage: ./pipex file1 cmd1 cmd2 file2\n");
	open_files(av, fd);
	while ()
		pipe_cmd(av, env, fd);
	return (0);
}
