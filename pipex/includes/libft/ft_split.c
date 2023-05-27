/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 12:49:11 by cparras           #+#    #+#             */
/*   Updated: 2023/02/16 13:36:51 by cparras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	words_nbr(char const *s, char c)
{
	size_t	words;
	size_t	check_char;

	words = 0;
	check_char = 0;
	while (*s)
	{
		if (*s != c && check_char == 0)
		{
			check_char = 1;
			words++;
		}
		else if (*s == c)
			check_char = 0;
		s++;
	}
	return (words);
}

static char	*print_string(char const *s, int head, int tail)
{
	char	*string;
	int		i;

	i = 0;
	string = (char *)malloc(sizeof(char) * (tail - head + 1));
	if (string == 0)
		return (NULL);
	while (head < tail)
		string[i++] = s[head++];
	string[i] = '\0';
	return (string);
}

static char	**ft_free(char **tab)
{
	size_t	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	j;
	size_t	i;
	size_t	adress;

	array = (char **)ft_calloc((words_nbr(s, c) + 1), sizeof(char *));
	if (array == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		adress = i;
		while (s[i] != c && s[i])
			i++;
		if (adress != i)
		{
			array[j++] = print_string(s, adress, i);
			if (!array[j - 1])
				return (ft_free(array));
		}
	}
	return (array);
}
