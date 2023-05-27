/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:11:20 by cparras           #+#    #+#             */
/*   Updated: 2023/05/02 17:44:08 by cparras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list    *ft_lstnew(int content)
{
    t_list    *list;

    list = (t_list *)malloc(sizeof(t_list));
    if (!list)
        return (NULL);
    list->content = content;
    list->next = NULL;
    return (list);
}

