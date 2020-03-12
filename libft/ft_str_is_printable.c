/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 14:44:40 by abaisago          #+#    #+#             */
/*   Updated: 2018/11/14 19:24:47 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int		ft_str_is_printable(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (!ft_isprint(s[i]))
			return (0);
		i++;
	}
	return (1);
}
