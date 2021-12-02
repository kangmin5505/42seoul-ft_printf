/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:55:25 by kangkim           #+#    #+#             */
/*   Updated: 2021/12/02 19:49:29 by kangkim          ###   ########.fr       */
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
int		parse_specifier(const char **fmt, t_info *fmt_info);
void	print_arg(va_list ap, t_info *fmt_info);

/* parse_detail function */
void	parse_flags(const char **_dp_fmt, t_info *fmt_info);
void	parse_width(const char **dp_fmt, t_info *fmt_info);
void	parse_precision(const char **dp_fmt, t_info *fmt_info);
int		parse_types(const char *fmt, t_info *fmt_info);

/* libft function */
int		ft_putchar(int c);
char	*ft_strchr(const char *s, int c);
int		ft_isdigit(int c);

/* fmt_info function */
void	init_fmt_info(t_info *fmt_info);

#endif
