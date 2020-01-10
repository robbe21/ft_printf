/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_c.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-ket <rvan-ket@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/06 20:35:08 by rvan-ket       #+#    #+#                */
/*   Updated: 2019/06/16 19:50:10 by rvan-ket      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	print_c(t_stringdata *data, int total)
{
	int length;

	length = (int)ft_strlen(data->str);
	if (!length)
		length++;
	if (data->minus)
	{
		total += ft_putchar_r(*data->str);
		total += print_width(data->width - length, ' ');
	}
	else
	{
		if (!data->zero)
			total += print_width(data->width - length, ' ');
		else
			total += print_width(data->width - length, '0');
		total += ft_putchar_r(*data->str);
	}
	return (total);
}
