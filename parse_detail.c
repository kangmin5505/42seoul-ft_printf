/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_detail.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:48:11 by kangkim           #+#    #+#             */
/*   Updated: 2021/12/02 19:48:15 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    parse_flags(const char **dp_fmt, t_info *fmt_info)
{
	printf("\nparse_flags : %c\n", **dp_fmt);
	(*dp_fmt)++;
}

void    parse_width(const char **dp_fmt, t_info *fmt_info)
{
	printf("\nparse_width : %c\n", **dp_fmt);
	(*dp_fmt)++;
}

void    parse_precision(const char **dp_fmt, t_info *fmt_info)
{
	printf("\nparse_precision : %c\n", **dp_fmt);
	(*dp_fmt)++;
	(*dp_fmt)++;
}

int     parse_types(const char *fmt, t_info *fmt_info)
{
	int	cnt;

	cnt = 0;
	printf("\nparse_types : %c\n", *fmt);
	return (cnt);
}
