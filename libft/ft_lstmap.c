/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:58:49 by abaisago          #+#    #+#             */
/*   Updated: 2018/11/13 18:21:44 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin;
	t_list	*next;

	if (lst == NULL)
		return (NULL);
	next = (*f)(lst);
	if (next == NULL)
		return (NULL);
	begin = next;
	while (lst->next != NULL)
	{
		lst = lst->next;
		next->next = (*f)(lst);
		if (next->next == NULL)
			return (NULL);
		next = next->next;
	}
	return (begin);
}
