/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 12:19:49 by abaisago          #+#    #+#             */
/*   Updated: 2018/11/17 17:10:47 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclr(t_list **begin_list)
{
	t_list	*prev;

	if (!(*begin_list))
		return ;
	while (*begin_list != NULL)
	{
		prev = (*begin_list);
		*begin_list = (*begin_list)->next;
		free(prev);
	}
}
