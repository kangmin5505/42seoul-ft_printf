/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_character.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:38:41 by kangkim           #+#    #+#             */
/*   Updated: 2021/12/06 12:21:14 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_character(va_list ap, t_info *fmt_info)
{
	int		cnt;
	char	c;
	char	*str;
	int		str_len;

	cnt = 0;
	if (fmt_info->type == 'c')
	{
		c = va_arg(ap, int);
		cnt += ft_putchar((int)c);
	}
	else
	{
		str = va_arg(ap, char *);
		str_len = ft_strlen(str);
		if (fmt_info->left_align == -1)
			cnt += print_str_right_align(str, str_len, fmt_info);
		else
			cnt += print_str_left_align(str, str_len, fmt_info);
	}
	return (cnt);
}
