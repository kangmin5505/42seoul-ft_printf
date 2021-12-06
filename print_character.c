/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_character.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:38:41 by kangkim           #+#    #+#             */
/*   Updated: 2021/12/06 23:02:06 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(char c, t_info *fmt_info)
{
	int	cnt;

	cnt = 0;
	if (fmt_info->left_align == -1)
	{
		while (fmt_info->width-- > 1)
			cnt += ft_putchar((int)' ');
		cnt += ft_putchar((int)c);
	}
	else
	{
		cnt += ft_putchar((int)c);
		while (fmt_info->width-- > 1)
			cnt += ft_putchar((int)' ');
	}
	return (cnt);
}

int	print_character(va_list *ap, t_info *fmt_info)
{
	int		cnt;
	char	c;
	char	*str;
	int		str_len;

	cnt = 0;
	if (fmt_info->type == 'c')
	{
		c = va_arg(*ap, int);
		cnt += print_c(c, fmt_info);
	}
	else
	{
		str = va_arg(*ap, char *);
		if (str == NULL)
			return (ft_putstr("(null)"));
		str_len = ft_strlen(str);
		if (fmt_info->left_align == -1)
			cnt += print_str_right_align(str, str_len, fmt_info);
		else
			cnt += print_str_left_align(str, str_len, fmt_info);
	}
	return (cnt);
}
