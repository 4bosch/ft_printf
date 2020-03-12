/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 23:59:21 by abaisago          #+#    #+#             */
/*   Updated: 2018/11/14 10:24:13 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	void	check_sign(int *sign, const char *str, size_t *i)
{
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign = -1;
		(*i)++;
	}
}

int				ft_atoi(const char *str)
{
	size_t				i;
	long long int		nbr;
	int					sign;

	nbr = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	check_sign(&sign, str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr *= 10;
		nbr += (str[i] - 48);
		if (nbr < 0)
		{
			if (sign == -1)
				return (0);
			else
				return (-1);
		}
		i++;
	}
	return (nbr * sign);
}
