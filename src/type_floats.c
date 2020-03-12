/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_floats.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 11:02:25 by abaisago          #+#    #+#             */
/*   Updated: 2019/03/20 11:38:16 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shared.h"

#include "floats.h"
#include "integers.h"
#include "output.h"

#include <stdlib.h>

void	type_f(va_list ap, t_spec *spec, t_buf *buf)
{
	t_string	conv;
	double		nbr;

	if (spec->size == SIZE_LLL)
		nbr = va_arg(ap, long double);
	else
		nbr = va_arg(ap, double);
	if (!(spec->flags & F_PRECI))
		spec->precision = 6;
	conv.str = ftoa(nbr, spec->precision);
	if (spec->flags & F_QUOTE)
		conv.str = nbr_grouping(&conv, ',', 3);
	conv.len = ft_strlen(conv.str);
	if (!(spec->flags & F_HASH) && spec->precision == 0)
		conv.str[conv.len - 1] = '\0';
	write_spec(buf, spec, &conv);
	free(conv.str);
}
