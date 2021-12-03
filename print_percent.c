/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:42:54 by kangkim           #+#    #+#             */
/*   Updated: 2021/12/03 18:43:03 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_percent(t_info *fmt_info)
{
	int	cnt;

	cnt = 0;
	if (fmt_info->left_align == 1)
	{
		cnt += ft_putchar((int)'%');
		while (fmt_info->width-- > 1)
			cnt += ft_putchar((int)' ');
	}
	else
	{
		while (fmt_info->width-- > 1)
		{
			if (fmt_info->nbr_zero_sign == 1)
				cnt += ft_putchar((int)'0');
			else
				cnt += ft_putchar((int)' ');
		}	
		cnt += ft_putchar((int)'%');
	}
	return (cnt);
}
