/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 12:31:25 by abaisago          #+#    #+#             */
/*   Updated: 2018/11/14 16:09:29 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int		ft_str_is_uppercase(const char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (!ft_isupper(s[i]))
			return (0);
		++i;
	}
	return (1);
}
