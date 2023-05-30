/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:42:29 by cparras           #+#    #+#             */
/*   Updated: 2023/02/16 13:35:30 by cparras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	len;
	char	*array;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	len = (size_t)(nmemb * size);
	if (len / nmemb != size || len / size != nmemb)
		return (NULL);
	array = malloc(len);
	if (array == NULL)
		return (NULL);
	ft_bzero(array, len);
	return (array);
}
