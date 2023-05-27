/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:26:26 by cparras           #+#    #+#             */
/*   Updated: 2023/02/16 13:37:09 by cparras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;
	char	*array;

	i = 0;
	j = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	array = malloc(sizeof(char) * (len1 + len2 + 1));
	if (array == 0)
		return (NULL);
	while (i < len1)
	{
		array[i] = s1[i];
		i++;
	}
	while (j < len2)
	{
		array[i + j] = s2[j];
		j++;
	}
	array[i + j] = '\0';
	return (array);
}
