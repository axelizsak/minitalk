/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aizsak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 10:21:49 by aizsak            #+#    #+#             */
/*   Updated: 2022/11/19 13:45:20 by aizsak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*elem;
	t_list	*next;

	if (!*lst)
		return ;
	elem = *lst;
	while (elem != NULL)
	{
		next = elem->next;
		(*del)(elem->content);
		free(elem);
		elem = next;
	}
	*lst = NULL;
}
