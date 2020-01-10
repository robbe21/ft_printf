/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   getargument_scp.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-ket <rvan-ket@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/29 21:07:58 by rvan-ket       #+#    #+#                */
/*   Updated: 2019/06/16 19:14:05 by rvan-ket      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	get_s(va_list ap, t_stringdata **data)
{
	char *str;

	str = va_arg(ap, char*);
	if (str)
		(*data)->str = ft_strdup(str);
	else if (!str)
		(*data)->str = ft_strdup("(null)");
	return (0);
}

int	get_c(va_list ap, t_stringdata **data)
{
	char c;

	c = (char)va_arg(ap, int);
	(*data)->str = (char*)malloc(sizeof(char) * 2);
	(*data)->str[0] = c;
	(*data)->str[1] = 0;
	return (0);
}

int	get_p(va_list ap, t_stringdata **data)
{
	long long		pointer;

	pointer = va_arg(ap, long long);
	if (!pointer && (*data)->prec_)
		(*data)->str = "";
	else
		(*data)->str = ft_itoa_base(pointer, 16);
	return (0);
}
