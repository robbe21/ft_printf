/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-ket <rvan-ket@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/25 15:15:45 by rvan-ket       #+#    #+#                */
/*   Updated: 2019/06/16 19:27:02 by rvan-ket      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct			s_stringdata
{
	int				width;
	int				precision;
	int				prec_;
	int				count;
	char			conversion;
	int				l;
	int				ll;
	int				h;
	int				hh;
	int				l_cap;
	int				hash;
	int				plus;
	int				zero;
	int				minus;
	int				space;
	int				nega;
	char			*str;
	int				roundup;
}						t_stringdata;

int						get_s(va_list ap, t_stringdata **data);
int						get_c(va_list ap, t_stringdata **data);
int						get_p(va_list ap, t_stringdata **data);
int						get_d(va_list ap, t_stringdata **data);
int						get_o(va_list ap, t_stringdata **data);
int						get_u(va_list ap, t_stringdata **data);
int						get_x(va_list ap, t_stringdata **data);
int						get_x_cap(va_list ap, t_stringdata **data);
int						get_f(va_list ap, t_stringdata **data);

int						print(t_stringdata *data);
int						print_d(t_stringdata *data, int total);
int						print_xx(t_stringdata *data, int total);
int						print_s(t_stringdata *data, int total);
int						print_c(t_stringdata *data, int total);
int						print_o(t_stringdata *data, int total);
int						print_p(t_stringdata *data, int total);
int						print_f(t_stringdata *data, int total);

int						print_width(int totalchar, char c);

int						ft_putstr_r(char const *s);
int						ft_putchar_r(char c);

char					*ft_itoa_base(unsigned long long value, long long base);
char					*ft_itoa_base_cap(unsigned long long value,
long long base);
char					*ft_itoa_base_s(long long value, long long base,
char *rep);

int						ft_nlen(long long nb);

void					ft_strjoin_free(char **tmp, char *str);
void					ft_strjoin_doublefree(char **tmp, char **str);

int						getflag(char *str, int i, t_stringdata **data);
int						getlengthmod(char *str, int i, t_stringdata **data);
int						getdata(char *str, va_list ap, int i,
t_stringdata *data);
int						getwidth(char *str, int i, t_stringdata **data);

#endif
