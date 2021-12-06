/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:19:45 by kangkim           #+#    #+#             */
/*   Updated: 2021/12/06 17:35:26 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(va_list ap)
{
	int			cnt;
	long long	nbr;
	char		*str;

	cnt = ft_putstr("0x");
	nbr = va_arg(ap, long long);
	str = NULL;
	if (nbr == (long long)NULL)
		cnt += ft_putchar((int)'0');
	else
	{
		str = ft_lltoa_base(nbr, 16);
		cnt += ft_putstr(str);
	}
	free(str);
	return (cnt);
}
