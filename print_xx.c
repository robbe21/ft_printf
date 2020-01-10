/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_xx.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-ket <rvan-ket@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/01 14:41:05 by rvan-ket       #+#    #+#                */
/*   Updated: 2019/06/14 19:20:06 by rvan-ket      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	print_nominus_xx(t_stringdata *data, int total, int x)
{
	if (data->zero && data->hash && data->conversion == 'x' &&
	data->str[0] != 0 && data->str[0] != '0')
		total += ft_putstr_r("0x");
	if (data->zero && data->hash && data->conversion == 'X' &&
	data->str[0] != 0 && data->str[0] != '0')
		total += ft_putstr_r("0X");
	if (data->zero && !data->precision)
		total += print_width(data->width - data->hash * 2 - x, '0');
	else
		total += print_width(data->width - data->hash * 2 - x, ' ');
	if (!data->zero && data->hash && data->conversion == 'x' &&
	data->str[0] != 0 && data->str[0] != '0')
		total += ft_putstr_r("0x");
	if (!data->zero && data->hash && data->conversion == 'X' &&
	data->str[0] != 0 && data->str[0] != '0')
		total += ft_putstr_r("0X");
	total += print_width(data->precision - (int)ft_strlen(data->str), '0');
	total += ft_putstr_r(data->str);
	return (total);
}

int	print_xx(t_stringdata *data, int total)
{
	int x;

	if (data->precision > (int)ft_strlen(data->str))
		x = data->precision;
	else
		x = (int)ft_strlen(data->str);
	if (data->str[0] == 0 || data->str[0] == '0')
		data->hash = 0;
	if (data->minus)
	{
		if (data->hash && data->conversion == 'x')
			total += ft_putstr_r("0x");
		if (data->hash && data->conversion == 'X')
			total += ft_putstr_r("0X");
		total += print_width(data->precision - (int)ft_strlen(data->str), '0');
		total += ft_putstr_r(data->str);
		total += print_width(data->width - data->hash * 2 - x, ' ');
	}
	else
		total += print_nominus_xx(data, total, x);
	return (total);
}
