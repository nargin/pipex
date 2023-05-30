/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:56:34 by romaurel          #+#    #+#             */
/*   Updated: 2023/05/30 16:53:10 by romaurel         ###   ########.fr       */
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

# define ERROR_HERE_DOC "Error\nPlease use as follow\n\
./pipex here_doc \"limiter\" \"cmd\" \"cmd1\" file"

# define ERROR_PIPEX "Error\nPlease use as follow\n\
./pipex file1 \"cmd1\" ... \"cmdn\" file2"

char	*check_path(char *cmd, char **ev);
void	exectute_cmd(char *av, char **ev);
void	child(char *av, char **ev);
void	here_doc(char *av, int ac);
void	here_doc_loop(char *av, int *fd);

#endif