/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 12:31:25 by abaisago          #+#    #+#             */
/*   Updated: 2018/11/14 16:09:04 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int		ft_str_is_lowercase(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (!ft_islower(s[i]))
			return (0);
		i++;
	}
	return (1);
}
