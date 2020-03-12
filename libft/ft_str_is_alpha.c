/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 11:58:16 by abaisago          #+#    #+#             */
/*   Updated: 2018/11/14 16:09:53 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int		ft_str_is_alpha(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (!ft_isalpha(s[i]))
			return (0);
		i++;
	}
	return (1);
}
