/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-ket <rvan-ket@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/29 22:18:46 by rvan-ket       #+#    #+#                */
/*   Updated: 2019/06/16 19:04:57 by rvan-ket      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*minuscheck(char *ptr, long long num, long long base)
{
	if (num < 0 && base == 10)
	{
		ptr--;
		*ptr = '-';
		return (ptr);
	}
	return (ptr);
}

int		checkmax(long long value)
{
	long long x;

	x = -9223372036854775807;
	if (value < x)
		return (1);
	return (0);
}

char	*ft_itoa_base_s(long long value, long long base, char *rep)
{
	static char	buf[300];
	char		*ptr;
	long long	num;

	ptr = &buf[299];
	*ptr = '\0';
	num = value;
	if (checkmax(num))
		return (ft_strdup("-9223372036854775808"));
	if (value < 0)
		value *= -1;
	if (value == 0)
	{
		ptr--;
		*ptr = rep[value % base];
	}
	while (value != 0)
	{
		ptr--;
		*ptr = rep[value % base];
		value /= base;
	}
	ptr = minuscheck(ptr, num, base);
	return (ptr);
}

char	*ft_itoa_base(unsigned long long value, long long base)
{
	static char			buf[300];
	char				*ptr;
	unsigned long long	num;
	char				*rep;

	rep = ft_strdup("0123456789abcdef");
	ptr = &buf[299];
	*ptr = '\0';
	num = value;
	if (value == 0)
	{
		ptr--;
		*ptr = rep[value % base];
	}
	while (value != 0)
	{
		ptr--;
		*ptr = rep[value % base];
		value /= base;
	}
	free(rep);
	return (ptr);
}

char	*ft_itoa_base_cap(unsigned long long value, long long base)
{
	static char			*rep;
	static char			buf[300];
	char				*ptr;
	unsigned long long	num;

	rep = ft_strdup("0123456789ABCDEF");
	ptr = &buf[299];
	*ptr = '\0';
	num = value;
	if (value == 0)
	{
		ptr--;
		*ptr = rep[value % base];
	}
	while (value != 0)
	{
		ptr--;
		*ptr = rep[value % base];
		value /= base;
	}
	free(rep);
	return (ptr);
}
