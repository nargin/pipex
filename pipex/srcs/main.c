/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 00:27:28 by cparras           #+#    #+#             */
/*   Updated: 2023/05/27 12:37:07 by cparras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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

int	main(int ac, char **av, char **env)
{
	int	i;
	int	fd1;
	int	fd2;

	if (ac < 5)
		printerr("Error\nPlease use as follow\n./pipex file1 \"cmd1\" ... \"cmdn\" file2", 1);
	if (ac >= 5)
	{
		i = 2;
		fd1 = open(av[1], O_RDONLY, 664);
		if (fd1 == -1)
			printerr("Error", 1);
		fd2 = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0664);
		if (fd2 == -1)
			printerr("Error", 1);
		dup2(fd1, STDIN_FILENO);
	}
	while (i < ac - 2)
		child(av[i++], env);
	dup2(fd2, STDOUT_FILENO);
	exectute_cmd(av[ac - 2], env);
}
