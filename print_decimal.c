/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:41:32 by kangkim           #+#    #+#             */
/*   Updated: 2021/12/03 18:50:06 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_decimal(va_list ap, t_info *fmt_info)
{
	int		cnt;
	char	c;
	char	*str;

	cnt = 0;
	if (fmt_info->type == 'c')
	{
		c = va_arg(ap, int);
		cnt += ft_putchar((int)c);
	}
	else
	{
		str = va_arg(ap, char *);
		cnt += ft_putstr(str);
	}
	return (cnt);
}
