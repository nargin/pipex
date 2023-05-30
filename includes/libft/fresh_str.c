/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fresh_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:07:43 by cparras           #+#    #+#             */
/*   Updated: 2023/05/29 17:50:34 by cparras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*fresh_str(char *str)
{
	int		i;
	char	*fresh;

	i = ft_strlen(str) + 1;
	fresh = ft_calloc(sizeof(char), i);
	if (!fresh)
		return (NULL);
	return (fresh);
}
