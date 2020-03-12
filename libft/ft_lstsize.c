/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:36:13 by abaisago          #+#    #+#             */
/*   Updated: 2018/11/14 19:27:22 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int		ft_lstsize(t_list *begin_list)
{
	size_t	cnt;
	t_list	*list;

	if (!begin_list)
		return (0);
	cnt = 0;
	list = begin_list;
	while (list != NULL)
	{
		++cnt;
		list = list->next;
	}
	return (cnt);
}
