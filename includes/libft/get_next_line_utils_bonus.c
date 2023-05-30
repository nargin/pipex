/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:24:18 by cparras           #+#    #+#             */
/*   Updated: 2023/04/12 14:25:13 by cparras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	lf_new_line(char *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack[i])
	{
		if (stack [i] == '\n')
			return (1);
		i++;
	}
	if (stack[i] == '\n')
		return (1);
	return (0);
}

char	*ft_strjoins(char **s1, char *s2)
{
	size_t	i;
	int		j;
	char	*array;

	if (!s2)
		return (NULL);
	i = 0;
	j = 0;
	if (!*s1)
		return (ft_strndup(s2, ft_strlenint(s2)));
	array = malloc(sizeof(char) * (ft_strlenint(*s1) + ft_strlenint(s2) + 1));
	if (!array)
		return (NULL);
	while ((*s1)[i])
		array[j++] = (*s1)[i++];
	i = 0;
	while (s2[i])
		array[j++] = s2[i++];
	array[j] = '\0';
	free(*s1);
	*s1 = array;
	return (array);
}

int	ft_strlenint(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strndup(char *s, int len)
{
	char	*str;
	int		i;

	i = 0;
	if (!s || !len)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
