/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_d.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-ket <rvan-ket@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/01 14:10:02 by rvan-ket       #+#    #+#                */
/*   Updated: 2019/06/14 22:55:56 by rvan-ket      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	print_minus_d(t_stringdata *data, int total, int x)
{
	if (data->space && !data->plus && !data->nega)
		total += ft_putchar_r(' ');
	if (data->nega)
		total += ft_putchar_r('-');
	if (data->plus)
		total += ft_putchar_r('+');
	total += print_width(data->precision - (int)ft_strlen(data->str), '0');
	total += ft_putstr_r(data->str);
	total += print_width(data->width - data->nega - data->plus - data->space -
	x, ' ');
	return (total);
}

int	print_nomin_d(t_stringdata *data, int total, int x)
{
	if (data->space && !data->plus && !data->nega)
		total += ft_putchar_r(' ');
	if (data->zero && data->nega)
		total += ft_putchar_r('-');
	if (data->zero && data->plus && !data->precision)
		total += ft_putchar_r('+');
	if (data->zero && !data->precision)
		total += print_width(data->width - data->nega - data->plus -
		data->space - x, '0');
	else
		total += print_width(data->width - data->nega - data->plus -
		data->space - x, ' ');
	if (data->nega && !data->zero)
		total += ft_putchar_r('-');
	if (data->zero && data->plus && data->precision)
		total += ft_putchar_r('+');
	if (!data->zero && data->plus)
		total += ft_putchar_r('+');
	total += print_width(data->precision - (int)ft_strlen(data->str), '0');
	total += ft_putstr_r(data->str);
	return (total);
}

int	print_d(t_stringdata *data, int total)
{
	int x;

	if (data->precision > (int)ft_strlen(data->str))
		x = data->precision;
	else
		x = (int)ft_strlen(data->str);
	if (data->minus)
		total += print_minus_d(data, total, x);
	else
		total += print_nomin_d(data, total, x);
	return (total);
}
