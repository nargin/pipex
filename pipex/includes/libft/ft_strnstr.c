/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:40:32 by cparras           #+#    #+#             */
/*   Updated: 2023/02/13 12:07:48 by cparras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;

	if ((!haystack || !needle) && n == 0)
		return (0);
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (*haystack && n)
	{
		if (*haystack == needle[0])
		{
			i = 1;
			while ((haystack[i] == needle[i])
				&& needle[i] && haystack[i] && i < n)
				i++;
			if (needle[i] == '\0')
				return ((char *)haystack);
		}
		haystack++;
		n--;
	}
	return (0);
}
