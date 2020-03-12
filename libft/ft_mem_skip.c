/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_mem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 18:01:40 by abaisago          #+#    #+#             */
/*   Updated: 2018/11/14 18:41:30 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

/*
** Parses the string (s) while the pointer to function (f) returns non-zero,
** the intent is for example to skip some characters int a string.
*/

size_t	ft_mem_skip(const char *s, int (*f)(int))
{
	size_t	i;

	i = 0;
	while ((*f)(s[i]))
		++i;
	return (i);
}
