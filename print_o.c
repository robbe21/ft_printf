/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_o.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-ket <rvan-ket@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/06 21:49:23 by rvan-ket       #+#    #+#                */
/*   Updated: 2019/06/14 19:15:09 by rvan-ket      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	print_minus_o(t_stringdata *data, int total, int x)
{
	if (data->hash && data->str[0] != 0 && data->str[0] != '0')
		total += ft_putstr_r("0");
	total += print_width(data->precision - (int)ft_strlen(data->str), '0');
	total += ft_putstr_r(data->str);
	total += print_width(data->width - data->hash - x, ' ');
	return (total);
}

int	print_o(t_stringdata *data, int total)
{
	int x;

	if ((data->str[0] == 0 || data->str[0] == '0') && !data->prec_)
		data->hash = 0;
	if (data->precision > (int)ft_strlen(data->str))
		x = data->precision;
	else
		x = (int)ft_strlen(data->str);
	if (data->minus)
		total += print_minus_o(data, total, x);
	else
	{
		if (data->zero && data->hash && data->precision)
			total += ft_putstr_r("0");
		if (data->zero && !data->precision && !data->prec_)
			total += print_width(data->width - data->hash - x, '0');
		else
			total += print_width(data->width - data->hash - x, ' ');
		if (data->hash && !data->precision)
			total += ft_putstr_r("0");
		total += print_width(data->precision - (int)ft_strlen(data->str), '0');
		total += ft_putstr_r(data->str);
	}
	return (total);
}
