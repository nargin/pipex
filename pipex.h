/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:56:34 by romaurel          #+#    #+#             */
/*   Updated: 2023/05/26 17:53:14 by romaurel         ###   ########.fr       */
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

typedef struct s_pipex
{
	char		**cmd;
	char		**env;
	char		*path;
	char		*file;
	int			fd;
	int			pipefd[2];
	int			pid;
	int			status;
}				t_pipex;

/**\*/
#define decode(s,t,u,m,p,e,d) m##s##u##t 
#define pipex decode(a,n,i,m,a,t,e) 
/**/

#endif