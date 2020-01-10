/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-ket <rvan-ket@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/31 17:16:35 by rvan-ket       #+#    #+#                */
/*   Updated: 2019/06/16 19:36:40 by rvan-ket      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	print_width(int totalchar, char c)
{
	int i;

	i = 0;
	while (i < totalchar)
	{
		ft_putchar_r(c);
		i++;
	}
	return (i);
}

int	before_print(t_stringdata **data)
{
	if ((*data)->nega)
		(*data)->plus = 0;
	if ((*data)->plus)
		(*data)->space = 0;
	if ((*data)->conversion == '%')
		(*data)->space = 0;
	if ((*data)->conversion == 'u')
	{
		(*data)->plus = 0;
		(*data)->space = 0;
	}
	if ((*data)->precision > (*data)->width && (*data)->conversion != 's'
	&& (*data)->conversion != 'c')
		(*data)->width = 0;
	return (0);
}

int	print(t_stringdata *data)
{
	int total;

	total = 0;
	before_print(&data);
	if (data->conversion == 'D' || data->conversion == 'd' ||
	data->conversion == 'i' || data->conversion == '%' ||
	data->conversion == 'u' || data->conversion == 'U')
		total += print_d(data, 0);
	else if (data->conversion == 'x' || data->conversion == 'X')
		total += print_xx(data, 0);
	else if (data->conversion == 'S' || data->conversion == 's')
		total += print_s(data, 0);
	else if (data->conversion == 'C' || data->conversion == 'c')
		total += print_c(data, 0);
	else if (data->conversion == 'O' || data->conversion == 'o')
		total += print_o(data, 0);
	else if (data->conversion == 'P' || data->conversion == 'p')
		total += print_p(data, 0);
	else if (data->conversion == 'f' || data->conversion == 'F')
		total += print_f(data, 0);
	else if (data->conversion && data->conversion != 16)
		total += ft_putchar_r(data->conversion);
	return (total);
}
