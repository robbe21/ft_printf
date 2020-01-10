/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_f.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-ket <rvan-ket@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/06 22:25:37 by rvan-ket       #+#    #+#                */
/*   Updated: 2019/06/14 19:12:55 by rvan-ket      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	print_f(t_stringdata *data, int total)
{
	data->precision = 0;
	return (print_d(data, total));
	if (data->plus)
		data->space = 0;
	if (data->space)
		total += ft_putchar_r(' ');
	if (data->minus)
	{
		total += ft_putstr_r(data->str);
		total += print_width(data->width - (int)ft_strlen(data->str) -
		data->space, ' ');
	}
	else
	{
		if (data->zero)
			total += print_width(data->width - (int)ft_strlen(data->str) -
			data->space, '0');
		else
			total += print_width(data->width - (int)ft_strlen(data->str) -
			data->space, ' ');
		total += ft_putstr_r(data->str);
	}
	return (total);
}
