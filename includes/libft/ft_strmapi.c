/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 12:49:30 by cparras           #+#    #+#             */
/*   Updated: 2023/02/16 13:37:23 by cparras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*array;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	array = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (array == 0)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		array[i] = f(i, s[i]);
		i++;
	}
	array[i] = '\0';
	return (array);
}
