/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   getdata.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-ket <rvan-ket@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/14 18:09:12 by rvan-ket       #+#    #+#                */
/*   Updated: 2019/06/14 19:46:57 by rvan-ket      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	stringdata_to_zero(t_stringdata **data)
{
	(*data)->plus = 0;
	(*data)->minus = 0;
	(*data)->hash = 0;
	(*data)->zero = 0;
	(*data)->space = 0;
	(*data)->precision = 0;
	(*data)->width = 0;
	(*data)->count = 0;
	(*data)->l = 0;
	(*data)->ll = 0;
	(*data)->h = 0;
	(*data)->hh = 0;
	(*data)->l_cap = 0;
	(*data)->nega = 0;
	(*data)->prec_ = 0;
	(*data)->roundup = 0;
	return (0);
}

int	getprecision(char *str, int i, t_stringdata **data)
{
	int		precision;

	if (str[i] == '.')
	{
		(*data)->prec_ = 1;
		i++;
		precision = ft_atoi(&str[i]);
		if (precision || str[i] == '0')
			i += ft_nlen(precision);
		(*data)->precision = precision;
	}
	return (i);
}

int	getconversion(char *str, int i, t_stringdata **data)
{
	if (!str[i])
		return (i);
	(*data)->conversion = str[i];
	return (i + 1);
}

int	getargument(va_list ap, t_stringdata **data, int i)
{
	if ((*data)->conversion == 's' || (*data)->conversion == 'S')
		get_s(ap, data);
	if ((*data)->conversion == 'c' || (*data)->conversion == 'C')
		get_c(ap, data);
	if ((*data)->conversion == 'p' || (*data)->conversion == 'P')
		get_p(ap, data);
	if ((*data)->conversion == 'd' || (*data)->conversion == 'i' ||
	(*data)->conversion == 'D')
		get_d(ap, data);
	if ((*data)->conversion == 'o' || (*data)->conversion == 'O')
		get_o(ap, data);
	if ((*data)->conversion == 'u' || (*data)->conversion == 'U')
		get_u(ap, data);
	if ((*data)->conversion == 'x')
		get_x(ap, data);
	if ((*data)->conversion == 'X')
		get_x_cap(ap, data);
	if ((*data)->conversion == 'f' || (*data)->conversion == 'F')
		get_f(ap, data);
	if ((*data)->conversion == '%')
		(*data)->str = ft_strdup("%");
	return (i);
}

int	getdata(char *str, va_list ap, int i, t_stringdata *data)
{
	stringdata_to_zero(&data);
	i++;
	i = getflag(str, i, &data);
	i = getwidth(str, i, &data);
	i = getprecision(str, i, &data);
	i = getlengthmod(str, i, &data);
	i = getconversion(str, i, &data);
	i = getargument(ap, &data, i);
	return (i);
}
