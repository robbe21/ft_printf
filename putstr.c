/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   putstr.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-ket <rvan-ket@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/31 18:49:16 by rvan-ket       #+#    #+#                */
/*   Updated: 2019/06/14 19:26:06 by rvan-ket      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar_r(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_r(char const *s)
{
	int i;

	i = 0;
	while (s[i])
		i += ft_putchar_r(s[i]);
	return (i);
}
