/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:54:14 by cparras           #+#    #+#             */
/*   Updated: 2023/04/12 14:20:37 by cparras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define FORMAT "csdipuxX%"

int	lf_arg(char c)
{
	int	i;

	i = -1;
	while (FORMAT[++i])
		if (c == FORMAT[i])
			return (1);
	return (0);
}

int	flag(char c, va_list arg)
{
	if (c == 'c')
		return (ft_putchar(va_arg(arg, int)));
	if (c == 'd')
		return (ft_putnbr(va_arg(arg, int)));
	if (c == '%')
		return (ft_putchar('%'));
	if (c == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	if (c == 'X')
		return (ft_puthexa(va_arg(arg, unsigned int), "0123456789ABCDEF"));
	if (c == 'x')
		return (ft_puthexa(va_arg(arg, unsigned int), "0123456789abcdef"));
	if (c == 'p')
		return (ft_adress(va_arg(arg, void *)));
	if (c == 's')
		return (ft_putstr(va_arg(arg, char *)));
	if (c == 'u')
		return (ft_putunbr(va_arg(arg, unsigned int)));
	return (0);
}

int	ft_adress(void *ptr)
{
	int				i;
	int				j;
	unsigned long	adress;
	char			*hex;
	char			rev[16];

	if (!ptr)
		return (ft_putstr("(nil)"));
	adress = (unsigned long)ptr;
	hex = "0123456789abcdef";
	j = 0;
	i = 0;
	while (adress != 0 || j == 0)
	{
		rev[j++] = hex[adress % 16];
		adress /= 16;
	}
	i += ft_putstr("0x");
	while (j)
		i += ft_putchar(rev[--j]);
	return (i);
}

int	ft_putunbr(unsigned int nb)
{
	int		i;
	int		j;
	char	rev[10];

	j = 0;
	i = 0;
	while (nb != 0 || j == 0)
	{
		rev[j++] = nb % 10 + 48;
		nb /= 10;
	}
	while (j)
		i += ft_putchar(rev[--j]);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list		arg;
	int			i;
	int			count;

	va_start(arg, str);
	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1] && lf_arg(str[i + 1]))
			count += flag(str[++i], arg);
		else
			count += ft_putchar(str[i]);
	}
	return (count);
}
