/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:20:45 by kangkim           #+#    #+#             */
/*   Updated: 2021/12/06 14:27:49 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_str_spacenzero(t_info *fmt_info, int str_len, char *str)
{
	int	cnt;
	int	width;
	int	prec;

	cnt = 0;
	width = fmt_info->width;
	prec = fmt_info->precision;
	if (ft_strchr(NUMTYPES, fmt_info->type) != NULL && \
			prec > str_len)
	{
		while (prec-- > str_len)
			cnt += ft_putchar((int)'0');
		cnt += ft_putstr(str);
		while (width - cnt > 0)
			cnt += ft_putchar((int)' ');
	}
	else
	{
		cnt += ft_putstr(str);
		while (width-- > str_len)
			cnt += ft_putchar((int)' ');
	}
	return (cnt);
}

int	print_spaceozero_str(t_info *fmt_info, int str_len, char *str)
{
	int	cnt;
	int	width;
	int	prec;

	cnt = 0;
	width = fmt_info->width;
	prec = fmt_info->precision;
	while (width > prec)
	{
		cnt += ft_putchar((int)' ');
		width--;
	}
	if (ft_strchr(NUMTYPES, fmt_info->type) != NULL && \
			prec > str_len)
	{
		while (prec-- > str_len)
			cnt += ft_putchar((int)'0');
	}
	else
	{
		while (width-- > str_len)
			cnt += ft_putchar((int)' ');	
	}
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
			cnt += print_str_spacenzero(fmt_info, str_len, str);
	}
	else
	{
		if (fmt_info->precision >= str_len)
			cnt += print_str_spacenzero(fmt_info, str_len, str);
		else if (ft_strchr(NUMTYPES, (int)fmt_info->type) != NULL)
			cnt += ft_putstr(str);
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
	int		cnt;

	cnt = 0;
	if (fmt_info->precision == -1)
	{
		if (str_len >= fmt_info->width)
			cnt += ft_putstr(str);
		else
			cnt += print_spaceozero_str(fmt_info, str_len, str);
	}
	else
	{
		if (fmt_info->precision >= str_len)
			cnt += print_spaceozero_str(fmt_info, str_len, str);
		else if (ft_strchr(NUMTYPES, (int)fmt_info->type) != NULL)
			cnt += ft_putstr(str);
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

