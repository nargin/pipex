/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:13:36 by cparras           #+#    #+#             */
/*   Updated: 2023/04/12 14:24:11 by cparras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*print_line(char **stack)
{
	int		i;
	char	*to_print;
	char	*tmp;

	if (!*stack)
		return (NULL);
	i = 0;
	tmp = *stack;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (tmp[i] == '\n')
		i++;
	to_print = ft_strndup(tmp, i);
	*stack = ft_strndup(tmp + i, ft_strlenint(tmp + i));
	free(tmp);
	return (to_print);
}

char	*del_mem(char **stack, int fd)
{
	if (fd < 0)
		return (NULL);
	if (*stack != NULL)
		free(*stack);
	*stack = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*stack[1024];
	char		*str;
	int			b_read;

	if (fd < 0 || read(fd, 0, 0) < 0 || !BUFFER_SIZE)
		return (del_mem(&stack[fd], fd));
	str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, str, BUFFER_SIZE);
		str[b_read] = '\0';
		stack[fd] = ft_strjoins(&stack[fd], str);
		if (lf_new_line(stack[fd]))
			break ;
	}
	if (str)
		free(str);
	str = NULL;
	return (print_line(&stack[fd]));
}
