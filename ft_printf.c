/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:52:33 by kangkim           #+#    #+#             */
/*   Updated: 2021/12/02 19:54:30 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_arg(va_list ap, t_info *fmt_info)
{
	char	*s;

	s = va_arg(ap, char *);
	printf("arg : %s\n", s);
}

int	parse_specifier(const char **fmt, t_info *fmt_info)
{
	int	cnt;

	if (ft_strchr(FLAGS, **fmt) != NULL)
		parse_flags(&(*fmt), fmt_info);
	if (ft_isdigit(**fmt) == 1)
		parse_width(&(*fmt), fmt_info);
	if (**fmt == '.')
		parse_precision(&(*fmt), fmt_info);
	if (ft_strchr(TYPES, **fmt) != NULL)
		cnt = parse_types(*fmt, fmt_info);
	return (cnt);
}

int	parse_fmt(va_list ap, const char *fmt)
{
	t_info	*fmt_info;
	int		cnt;

	cnt = 0;
	while (*fmt != '\0')
	{
		if (*fmt != '%')
			cnt += ft_putchar((int)*fmt);
		else
		{
			fmt++;
			fmt_info = (t_info *)malloc(sizeof(t_info));
			if (fmt_info == NULL)
				return (0);
			init_fmt_info(fmt_info);
			cnt += parse_specifier(&fmt, fmt_info);
			print_arg(ap, fmt_info);
			free(fmt_info);
			fmt_info = NULL;
		}
		fmt++;
	}
	return (cnt);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		cnt;

	va_start(ap, fmt);
	cnt = parse_fmt(ap, fmt);
	va_end(ap);
	return (cnt);
}
