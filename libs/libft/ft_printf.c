/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:14:56 by alermolo          #+#    #+#             */
/*   Updated: 2024/01/25 16:25:28 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_format(char c, va_list args)
{
	int	printed;

	printed = 0;
	if (c == 'c')
		printed += ft_printchar(va_arg(args, int));
	else if (c == 's')
		printed += ft_printstr(va_arg(args, char *));
	else if (c == 'p')
		printed += ft_printaddr(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		printed += ft_printnbr(va_arg(args, int));
	else if (c == 'u')
		printed += ft_printnbr_unsigned(va_arg(args, unsigned int));
	else if (c == 'x')
		printed += ft_printnbr_hex(va_arg(args, unsigned int));
	else if (c == 'X')
		printed += ft_printnbr_hex_caps(va_arg(args, unsigned int));
	else if (c == '%')
		printed += ft_printchar('%');
	return (printed);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		printed;
	va_list	args;

	i = 0;
	printed = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i + 1] && s[i] == '%')
		{
			printed += print_format(s[i + 1], args);
			i++;
		}
		else
			printed += ft_printchar(s[i]);
		i++;
	}
	va_end(args);
	return (printed);
}
