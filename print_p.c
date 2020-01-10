/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_p.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-ket <rvan-ket@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/06 22:25:29 by rvan-ket       #+#    #+#                */
/*   Updated: 2019/06/16 18:42:34 by rvan-ket      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	print_nominus_p(t_stringdata *data, int total, int x)
{
	if (data->zero)
		total += ft_putstr_r("0x");
	if (data->zero && !data->precision)
		total += print_width(data->width - 2 - x, '0');
	else
		total += print_width(data->width - 2 - x, ' ');
	if (!data->zero)
		total += ft_putstr_r("0x");
	total += print_width(data->precision - (int)ft_strlen(data->str), '0');
	total += ft_putstr_r(data->str);
	return (total);
}

int	print_p(t_stringdata *data, int total)
{
	int x;

	if (data->precision > (int)ft_strlen(data->str))
		x = data->precision;
	else
		x = (int)ft_strlen(data->str);
	if (data->minus)
	{
		total += ft_putstr_r("0x");
		total += print_width(data->precision - (int)ft_strlen(data->str), '0');
		total += ft_putstr_r(data->str);
		total += print_width(data->width - 2 - x, ' ');
	}
	else
		total += print_nominus_p(data, total, x);
	return (total);
}
