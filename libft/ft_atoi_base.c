/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 21:40:10 by abaisago          #+#    #+#             */
/*   Updated: 2018/11/14 19:47:21 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static void		sign_and_special_chars(char *str, size_t *i, int *neg)
{
	while ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == 32)
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*neg = -1;
		(*i)++;
	}
}

static int		wrong_chars_repeat(char *base)
{
	size_t	c;
	size_t	i;

	c = 0;
	i = 0;
	while (base[c] != '\0')
	{
		while (base[i] != '\0')
		{
			if (base[c] == base[i] && c != i)
				return (1);
			i++;
		}
		i = 0;
		c++;
	}
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+')
			return (1);
		if (base[i] < 32 || base[i] > 126)
			return (1);
		i++;
	}
	return (0);
}

static int		is_in_base(char c, char *base)
{
	size_t	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int				ft_atoi_base(char *str, char *base)
{
	size_t	i;
	int		nbr;
	int		neg;
	size_t	base_len;
	size_t	str_len;

	i = 0;
	nbr = 0;
	neg = 1;
	base_len = ft_strlen(base);
	str_len = ft_strlen(str);
	if (base_len < 2 || str_len < 1 || wrong_chars_repeat(base))
		return (0);
	sign_and_special_chars(str, &i, &neg);
	while (is_in_base(str[i], base) != -1)
	{
		nbr *= base_len;
		nbr += is_in_base(str[i], base);
		i++;
	}
	nbr *= neg;
	return (nbr);
}
