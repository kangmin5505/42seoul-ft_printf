/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:55:25 by kangkim           #+#    #+#             */
/*   Updated: 2021/12/03 21:11:12 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
/* delete library */
# include <stdio.h>

# define FLAGS "-0# +"
# define TYPES "cspdiuxX%"

typedef struct s_info
{
	int		left_align;
	int		nbr_zero_sign;
	int		nbr_hash;
	int		nbr_space_sign;
	int		nbr_plus_sign;
	int		precision;
	int		nbr_base;
	int		width;
	char	type;
}	t_info;

/* ft_printf function */
int		ft_printf(const char *fmt, ...);
int		parse_fmt(va_list ap, const char *fmt);
void	parse_specifier(const char **fmt, t_info *fmt_info);
int		print_arg(va_list ap, t_info *fmt_info);

/* parse_specifier_detail function */
void	parse_flags(const char **_dp_fmt, t_info *fmt_info);
void	parse_width(const char **dp_fmt, t_info *fmt_info);
void	parse_precision(const char **dp_fmt, t_info *fmt_info);
void	parse_types(const char *fmt, t_info *fmt_info);
int		print_arg(va_list ap, t_info *fmt_info);

/* print_character function */
int		print_character(va_list ap, t_info *fmt_info);
int		print_str_left_align(char *str, int str_len, t_info *fmt_info);
int		print_str_right_align(char *str, int str_len, t_info *fmt_info);
int		print_space_str(t_info *fmt_info, int str_len, char *str);
int		print_str_space(t_info *fmt_info, int str_len, char *str);

/* print_pointer function */
int		print_pointer(va_list ap, t_info *fmt_info);

/* print_decimal function */
int		print_decimal(va_list ap, t_info *fmt_info);

/* print_hexa function */
int		print_hexa(va_list ap, t_info *fmt_info);

/* print_percent function */
int		print_percent(t_info *fmt_info);

/* libft function */
int		ft_putchar(int c);
int		ft_putstr(const char *s);
char	*ft_strchr(const char *s, int c);
int		ft_isdigit(int c);
int		ft_strlen(const char *s);

/* fmt_info function */
void	init_fmt_info(t_info *fmt_info);

#endif
