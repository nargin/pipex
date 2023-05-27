/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 12:48:18 by cparras           #+#    #+#             */
/*   Updated: 2023/02/16 13:35:44 by cparras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	number_len(int n)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*string;
	size_t	len;
	long	nbr;

	len = number_len(n);
	nbr = n;
	string = (char *)malloc(sizeof(char) * (len + 1));
	if (string == 0)
		return (NULL);
	string[len] = '\0';
	if (nbr < 0)
	{
		string[0] = '-';
		nbr = -nbr;
	}
	if (nbr == 0)
		string[0] = '0';
	while (nbr != 0)
	{
		len--;
		string[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (string);
}
