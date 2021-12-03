/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_character.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:38:41 by kangkim           #+#    #+#             */
/*   Updated: 2021/12/03 21:11:41 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_str_space(t_info *fmt_info, int str_len, char *str)
{
	int	cnt;

	cnt = 0;
	cnt += ft_putstr(str);
	while (fmt_info->width-- > str_len)
		cnt += ft_putchar((int)' ');
	return (cnt);
}

int	print_space_str(t_info *fmt_info, int str_len, char *str)
{
	int	cnt;

	cnt = 0;
	while (fmt_info->width-- > str_len)
		cnt += ft_putchar((int)' ');	
	cnt += ft_putstr(str);
	return (cnt);
}

int	print_str_left_align(char *str, int str_len, t_info *fmt_info)
{
	int	cnt;

	cnt = 0;
	if (fmt_info->precision == -1)
	{
		if (str_len >= fmt_info->width)
			cnt += ft_putstr(str);
		else
			cnt += print_str_space(fmt_info, str_len, str);
	}
	else
	{
		if (fmt_info->precision >= str_len)
			cnt += print_str_space(fmt_info, str_len, str);
		else
		{
			str_len = fmt_info->precision;
			while (str_len--)
				cnt += ft_putchar((int)*str++);
			while (fmt_info->width-- > fmt_info->precision)
				cnt += ft_putchar((int)' ');
		}
	}
	return (cnt);
}

int	print_str_right_align(char *str, int str_len, t_info *fmt_info)
{
	int	cnt;

	cnt = 0;
	if (fmt_info->precision == -1)
	{
		if (str_len >= fmt_info->width)
			cnt += ft_putstr(str);
		else
			cnt += print_space_str(fmt_info, str_len, str);
	}
	else
	{
		if (fmt_info->precision >= str_len)
			cnt += print_space_str(fmt_info, str_len, str);
		else
		{
			while (fmt_info->width-- > fmt_info->precision)
				cnt += ft_putchar((int)' ');
			while (fmt_info->precision--)
				cnt += ft_putchar((int)*str++);
		}
	}
	return (cnt);
}

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
