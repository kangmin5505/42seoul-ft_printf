/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:40:33 by kangkim           #+#    #+#             */
/*   Updated: 2021/12/03 18:41:07 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(va_list ap, t_info *fmt_info)
{
	t_info	*info1;

	if (ap == NULL)
	{
	}
	info1 = fmt_info;
	printf("here is print_pointer function\n");
	return (0);
}
