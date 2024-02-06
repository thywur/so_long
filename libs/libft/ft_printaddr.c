/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printaddr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:26:47 by alermolo          #+#    #+#             */
/*   Updated: 2024/01/25 16:24:49 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printaddr(unsigned long long addr)
{
	char	buffer[19];
	char	*base;
	int		i;
	int		printed;

	i = 0;
	base = "0123456789abcdef";
	if (!addr)
		return (ft_printstr("(nil)"));
	while (addr > 0)
	{
		buffer[i++] = base[(unsigned char)addr % 16];
		addr /= 16;
	}
	if (i < 18 && i + 1 < 18)
	{
		buffer[i] = 'x';
		buffer[i + 1] = '0';
		i += 2;
	}
	i--;
	printed = 0;
	while (i + 1 > 0)
		printed += ft_printchar(buffer[i--]);
	return (printed);
}
