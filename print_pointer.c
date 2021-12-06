/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:19:45 by kangkim           #+#    #+#             */
/*   Updated: 2021/12/06 22:28:15 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(va_list *ap)
{
	int				cnt;
	unsigned long	nbr;
	char			*str;

	cnt = ft_putstr("0x");
	nbr = va_arg(*ap, unsigned long);
	str = NULL;
	if (nbr == (unsigned long)NULL)
		cnt += ft_putchar((int)'0');
	else
	{
		str = ft_ultoa_base(nbr, 16);
		cnt += ft_putstr(str);
	}
	free(str);
	return (cnt);
}
