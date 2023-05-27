/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:08:16 by cparras           #+#    #+#             */
/*   Updated: 2023/04/12 14:20:30 by cparras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	int		i;
	char	rev[10];
	int		j;

	i = 0;
	j = 0;
	if (nb == INT_MIN)
		return ((void)write(1, "-2147483648", 11), 11);
	if (nb < 0)
	{
		i += ft_putchar('-');
		nb *= -1;
	}
	while (nb != 0 || j == 0)
	{
		rev[j++] = nb % 10 + '0';
		nb /= 10;
	}
	while (j)
		i += ft_putchar(rev[--j]);
	return (i);
}

int	ft_puthexa(unsigned int nb, char *base)
{
	int		i;
	int		j;
	char	rev[12];

	j = 0;
	i = 0;
	while (nb != 0 || j == 0)
	{
		rev[j++] = base[nb % 16];
		nb /= 16;
	}
	while (j)
		i += ft_putchar(rev[--j]);
	return (i);
}
