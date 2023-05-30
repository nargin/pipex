/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 00:27:28 by cparras           #+#    #+#             */
/*   Updated: 2023/05/30 16:51:35 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	here_doc_loop(char *av, int *fd)
{
	char	*line;

	close(fd[0]);
	while (1)
	{
		line = get_next_line(0);
		if (ft_strncmp(line, av, ft_strlen(line)) == 0)
			exit(EXIT_SUCCESS);
		write(fd[1], line, ft_strlen(line));
		free(line);
	}
}

void	child(char *av, char **ev)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		return ;
	pid = fork();
	if (pid == -1)
		return ;
	if (!pid)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		exectute_cmd(av, ev);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

void	here_doc(char *av, int ac)
{
	pid_t	pid;
	int		fd[2];
	char	*line;

	if (ac < 6)
		printerr(ERROR_HERE_DOC, 1);
	if (pipe(fd) == -1)
		printerr("Error", 1);
	pid = fork();
	if (pid == 0)
	{
		here_doc_loop(av, fd);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
}

int	main(int ac, char **av, char **env)
{
	int	i;
	int	fd[2];

	if (ac < 5)
		printerr(ERROR_PIPEX, 1);
	fd[1] = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd[1] == -1)
		printerr("Error", 1);
	if (!ft_strncmp(av[1], "here_doc", 8))
	{
		i = 3;
		here_doc(ft_strjoin(av[2], "\n"), ac);
	}
	else
	{
		i = 2;
		fd[0] = open(av[1], O_RDONLY, 664);
		if (fd[0] == -1)
			printerr("Error", 1);
		dup2(fd[0], STDIN_FILENO);
	}
	while (i < ac - 2)
		child(av[i++], env);
	dup2(fd[1], STDOUT_FILENO);
	exectute_cmd(av[ac - 2], env);
}
