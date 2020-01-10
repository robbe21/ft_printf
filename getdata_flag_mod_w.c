/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   getdata_flag_mod_w.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-ket <rvan-ket@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/14 18:10:36 by rvan-ket       #+#    #+#                */
/*   Updated: 2019/06/14 19:21:43 by rvan-ket      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	getflag(char *str, int i, t_stringdata **data)
{
	while (str[i] == '+' || str[i] == '-' || str[i] == ' ' || str[i] == '0'
	|| str[i] == '#')
	{
		if (str[i] == '-')
			(*data)->minus = 1;
		else if (str[i] == '+')
			(*data)->plus = 1;
		else if (str[i] == ' ')
			(*data)->space = 1;
		else if (str[i] == '0')
			(*data)->zero = 1;
		else if (str[i] == '#')
			(*data)->hash = 1;
		i++;
	}
	return (i);
}

int	getlengthmod(char *str, int i, t_stringdata **data)
{
	if (str[i] == 'l' && str[i + 1] == 'l')
	{
		(*data)->ll = 1;
		i++;
	}
	else if (str[i] == 'l')
		(*data)->l = 1;
	else if (str[i] == 'h' && str[i + 1] == 'h')
	{
		(*data)->hh = 1;
		i++;
	}
	else if (str[i] == 'h')
		(*data)->h = 1;
	else if (str[i] == 'L')
		(*data)->l_cap = 1;
	else
		return (i);
	return (i + 1);
}

int	getwidth(char *str, int i, t_stringdata **data)
{
	int		width;

	if (0 == str[i])
		return (i);
	width = ft_atoi(&str[i]);
	if (width)
		i += ft_nlen(width);
	(*data)->width = width;
	return (i);
}
