/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:45:20 by cparras           #+#    #+#             */
/*   Updated: 2023/02/06 18:47:40 by cparras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	l_dest;
	size_t	l_src;

	l_dest = ft_strlen(dest);
	l_src = 0;
	if (size == 0)
		return (ft_strlen(src));
	if (l_dest > size)
		return (size + ft_strlen(src));
	while ((l_dest + l_src) < size - 1 && src[l_src])
	{
		dest[l_dest + l_src] = src[l_src];
		l_src++;
	}
	if (l_dest + l_src < size)
		dest[l_src + l_dest] = '\0';
	return (l_dest + ft_strlen(src));
}
