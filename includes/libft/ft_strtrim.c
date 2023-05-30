/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:33:03 by cparras           #+#    #+#             */
/*   Updated: 2023/02/16 13:37:37 by cparras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	head;
	size_t	tail;
	char	*array;

	head = 0;
	tail = ft_strlen(s1);
	if (!set || !s1)
		return (NULL);
	while (s1[head] && ft_strchr(set, s1[head]))
		head++;
	while (tail > head && ft_strchr(set, s1[tail - 1]))
		tail--;
	array = (char *)malloc(sizeof(char) * (tail - head + 1));
	if (array == NULL)
		return (NULL);
	ft_memcpy(array, s1 + head, tail - head);
	array[tail - head] = '\0';
	return (array);
}
