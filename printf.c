/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-ket <rvan-ket@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/25 15:06:06 by rvan-ket       #+#    #+#                */
/*   Updated: 2019/06/16 18:45:09 by rvan-ket      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	free_data(t_stringdata *data)
{
	if (data->conversion == 'f' || data->conversion == 'C'
	|| data->conversion == 'c' ||
	data->conversion == 's' || data->conversion == '%' ||
	data->conversion == 'S' || (data->conversion == 'd' && data->nega))
		free(data->str);
	if (data)
		free(data);
}

int		ft_printf(char *format, ...)
{
	int				i;
	va_list			ap;
	t_stringdata	*data;
	int				total;

	total = 0;
	i = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			data = (t_stringdata *)malloc(sizeof(t_stringdata));
			i = getdata(format, ap, i, data);
			total += print(data);
			free_data(data);
			continue ;
		}
		total += ft_putchar_r(format[i]);
		i++;
	}
	va_end(ap);
	return (total);
}
