/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_s.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-ket <rvan-ket@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/06 20:04:11 by rvan-ket       #+#    #+#                */
/*   Updated: 2019/06/16 19:19:15 by rvan-ket      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	print_s(t_stringdata *data, int total)
{
	int length;

	length = 0;
	if (data->prec_)
		data->str[data->precision] = 0;
	if (data->str)
		length = (int)ft_strlen(data->str);
	if (data->minus)
	{
		total += ft_putstr_r(data->str);
		total += print_width(data->width - length, ' ');
	}
	else
	{
		if (!data->zero)
			total += print_width(data->width - length, ' ');
		else
			total += print_width(data->width - length, '0');
		total += ft_putstr_r(data->str);
	}
	return (total);
}
