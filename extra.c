/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   extra.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-ket <rvan-ket@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/13 21:38:38 by rvan-ket       #+#    #+#                */
/*   Updated: 2019/06/16 17:20:28 by rvan-ket      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_strjoin_doublefree(char **tmp, char **str)
{
	char	*x;
	char	*z;

	z = *str;
	x = *tmp;
	*tmp = ft_strjoin(*tmp, *str);
	free(z);
	free(x);
}

int		ft_nlen(long long nb)
{
	int			i;
	long long	x;

	x = -9223372036854775807;
	if (nb == 0)
		return (1);
	i = 0;
	if (nb == x)
		return (19);
	nb < 0 ? nb = -nb : 0;
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}
