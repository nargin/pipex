/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:14:20 by cparras           #+#    #+#             */
/*   Updated: 2023/05/03 18:38:00 by cparras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
	*lst = NULL;
}
