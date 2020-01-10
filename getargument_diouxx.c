/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   getargument_diouxx.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-ket <rvan-ket@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/29 21:49:25 by rvan-ket       #+#    #+#                */
/*   Updated: 2019/06/16 19:06:12 by rvan-ket      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	get_d(va_list ap, t_stringdata **data)
{
	if ((*data)->l)
		(*data)->str = ft_itoa_base_s(va_arg(ap, long), 10,
		"0123456789abcdef");
	else if ((*data)->ll)
		(*data)->str = ft_itoa_base_s(va_arg(ap, long long), 10,
		"0123456789abcdef");
	else if ((*data)->h)
		(*data)->str = ft_itoa_base_s((short)va_arg(ap, int), 10,
		"0123456789abcdef");
	else if ((*data)->hh)
		(*data)->str = ft_itoa_base_s((signed char)va_arg(ap, int), 10,
		"0123456789abcdef");
	else
		(*data)->str = ft_itoa_base_s(va_arg(ap, int), 10,
		"0123456789abcdef");
	if ((*data)->str[0] == '-')
	{
		(*data)->nega = 1;
		(*data)->str = ft_strdup(&((*data)->str[1]));
	}
	if ((*data)->prec_ && (*data)->str[0] == '0')
		(*data)->str[0] = 0;
	return (0);
}

int	get_o(va_list ap, t_stringdata **data)
{
	if ((*data)->l)
		(*data)->str = ft_itoa_base(va_arg(ap, unsigned long), 8);
	else if ((*data)->ll)
		(*data)->str = ft_itoa_base(va_arg(ap, unsigned long long), 8);
	else if ((*data)->h)
		(*data)->str = ft_itoa_base((unsigned short)va_arg(ap, int), 8);
	else if ((*data)->hh)
		(*data)->str = ft_itoa_base((unsigned char)va_arg(ap, int), 8);
	else
		(*data)->str = ft_itoa_base(va_arg(ap, unsigned int), 8);
	if ((*data)->prec_ && (*data)->str[0] == '0')
		(*data)->str[0] = 0;
	return (0);
}

int	get_u(va_list ap, t_stringdata **data)
{
	if ((*data)->l)
		(*data)->str = ft_itoa_base(va_arg(ap, unsigned long), 10);
	else if ((*data)->ll)
		(*data)->str = ft_itoa_base(va_arg(ap, unsigned long long), 10);
	else if ((*data)->h)
		(*data)->str = ft_itoa_base((unsigned short)va_arg(ap, int), 10);
	else if ((*data)->hh)
		(*data)->str = ft_itoa_base((unsigned char)va_arg(ap, int), 10);
	else
		(*data)->str = ft_itoa_base(va_arg(ap, unsigned int), 10);
	if ((*data)->prec_ && (*data)->str[0] == '0')
		(*data)->str[0] = 0;
	return (0);
}

int	get_x(va_list ap, t_stringdata **data)
{
	if ((*data)->l)
		(*data)->str = ft_itoa_base(va_arg(ap, unsigned long), 16);
	else if ((*data)->ll)
		(*data)->str = ft_itoa_base(va_arg(ap, unsigned long long), 16);
	else if ((*data)->h)
		(*data)->str = ft_itoa_base((unsigned short)va_arg(ap, int), 16);
	else if ((*data)->hh)
		(*data)->str = ft_itoa_base((unsigned char)va_arg(ap, int), 16);
	else
		(*data)->str = ft_itoa_base(va_arg(ap, unsigned int), 16);
	if ((*data)->prec_ && (*data)->str[0] == '0')
		(*data)->str[0] = 0;
	return (0);
}

int	get_x_cap(va_list ap, t_stringdata **data)
{
	if ((*data)->l)
		(*data)->str = ft_itoa_base_cap(va_arg(ap, unsigned long), 16);
	else if ((*data)->ll)
		(*data)->str = ft_itoa_base_cap(va_arg(ap, unsigned long long), 16);
	else if ((*data)->h)
		(*data)->str = ft_itoa_base_cap((unsigned short)va_arg(ap, int), 16);
	else if ((*data)->hh)
		(*data)->str = ft_itoa_base_cap((unsigned char)va_arg(ap, int), 16);
	else
		(*data)->str = ft_itoa_base_cap(va_arg(ap, unsigned int), 16);
	if ((*data)->prec_ && (*data)->str[0] == '0')
		(*data)->str[0] = 0;
	return (0);
}
