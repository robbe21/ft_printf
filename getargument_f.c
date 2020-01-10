/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   getargument_f.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-ket <rvan-ket@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/31 16:34:02 by rvan-ket       #+#    #+#                */
/*   Updated: 2019/06/16 18:55:50 by rvan-ket      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*roundup(char *fstr, t_stringdata **data, int i)
{
	int		len;

	fstr[i + 1] = 0;
	len = i - (*data)->precision;
	while (fstr[i] == '9' || fstr[i] == '.')
	{
		if (fstr[i] != '.')
			fstr[i] = '0';
		i--;
		if (i == 0)
		{
			if (fstr[i] < '9')
				fstr[i] += 1;
			else
			{
				(*data)->roundup = 1;
				fstr[0] = '0';
				fstr = ft_strjoin("1", fstr);
			}
			return (fstr);
		}
	}
	if (fstr[i] != '9')
		fstr[i] += 1;
	return (fstr);
}

char		*roundup_f_string(char *fstr, t_stringdata **data)
{
	int	i;

	i = 0;
	while (fstr[i])
	{
		i++;
		if (fstr[i] == '.')
			break ;
	}
	i += (*data)->precision + 1;
	if (fstr[i] >= '5' && fstr[i] <= '9')
	{
		i--;
		if (fstr[i] >= '0' && fstr[i] <= '8')
			fstr[i] += 1;
		else if (fstr[i] == '9')
			return (roundup(fstr, data, i));
	}
	return (fstr);
}

char		**ft_afterdot(long double numb, t_stringdata **data)
{
	int		i;
	char	*str;
	char	**s;

	str = (char*)malloc(sizeof(char) * ((*data)->precision + 2));
	numb -= (int)numb;
	i = 0;
	while (i <= (*data)->precision)
	{
		numb = numb * 10;
		str[i] = (int)numb + '0';
		i++;
		numb -= (int)numb;
	}
	str[i] = 0;
	s = &str;
	return (s);
}

int			get_f_no_p(long double numb, t_stringdata **data)
{
	long double	temp;
	int			inumb;

	temp = numb - (int)numb;
	temp *= 10;
	if (temp >= 5)
		inumb = numb + 1;
	else
		inumb = numb;
	(*data)->str = ft_itoa_base_s(inumb, 10, "0123456789abcdef");
	if ((*data)->hash)
		ft_strcat((*data)->str, ".");
	(*data)->conversion = 'd';
	return (0);
}

int			get_f(va_list ap, t_stringdata **data)
{
	long double	numb;
	char		*str;

	if ((*data)->l_cap)
		numb = va_arg(ap, long double);
	else
		numb = (double)va_arg(ap, double);
	if (numb < 0)
	{
		numb *= -1;
		(*data)->nega = 1;
	}
	if ((*data)->prec_ && !(*data)->precision)
		return (get_f_no_p(numb, data));
	else if (!(*data)->prec_ && !(*data)->precision)
		(*data)->precision = 6;
	str = ft_strdup(ft_itoa_base_s((int)numb, 10, "0123456789abcdef"));
	str[ft_nlen((int)numb)] = '.';
	ft_strjoin_doublefree(&str, ft_afterdot(numb, data));
	str = roundup_f_string(str, data);
	if ((*data)->precision >= 1 && !(*data)->roundup)
		str[ft_strlen(str) - 1] = 0;
	(*data)->str = str;
	return (0);
}
