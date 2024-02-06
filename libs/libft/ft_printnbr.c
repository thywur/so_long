/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:42:42 by alermolo          #+#    #+#             */
/*   Updated: 2024/01/25 16:25:05 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printnbr(int n)
{
	long int	nb;
	int			printed;

	nb = (long int)n;
	printed = 0;
	if (nb < 0)
	{
		printed += ft_printchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		printed += ft_printnbr(nb / 10);
		printed += ft_printnbr(nb % 10);
	}
	if (nb >= 0 && nb < 10)
		return (printed += ft_printchar(nb + '0'));
	return (printed);
}

int	ft_printnbr_unsigned(unsigned int n)
{
	int	printed;

	printed = 0;
	if (n >= 10)
	{
		printed += ft_printnbr(n / 10);
		printed += ft_printnbr(n % 10);
	}
	if (n >= 0 && n < 10)
		return (ft_printchar(n + '0'));
	return (printed);
}
