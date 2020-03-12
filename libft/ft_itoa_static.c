/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:02:17 by abaisago          #+#    #+#             */
/*   Updated: 2019/02/08 17:54:52 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static	void	fill_string(char *str, size_t *i, long long nbr)
{
	if (nbr >= 10)
	{
		fill_string(str, i, nbr / 10);
		fill_string(str, i, nbr % 10);
	}
	else
	{
		str[*i] = nbr + '0';
		(*i)++;
	}
}

void			ft_itoa_static(char *tab[], int n)
{
	size_t		i;
	long long	nbr;

	i = 0;
	nbr = n;
	if (ft_abs(&nbr))
		(*tab)[i++] = '-';
	fill_string(*tab, &i, nbr);
}
