/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:56:34 by romaurel          #+#    #+#             */
/*   Updated: 2023/05/30 01:05:39 by cparras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <stdio.h>
# include "./libft/libft.h"

char	*check_path(char *cmd, char **ev);
void	exectute_cmd(char *av, char **ev);
void	child(char *av, char **ev);
void	here_doc(char *av, int ac);
void	here_doc_loop(char *av, int *fd);

#endif