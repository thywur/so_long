/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:11:01 by alermolo          #+#    #+#             */
/*   Updated: 2023/11/10 15:57:59 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(int n)
{
	int			len;
	long int	nb;

	len = 1;
	nb = (long int)n;
	if (nb < 0)
	{
		len++;
		nb = -nb;
	}
	while (nb >= 10)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			i;
	char		*str;
	long int	nb;

	str = (char *)malloc(sizeof(char) * (get_len(n) + 1));
	if (!str)
		return (NULL);
	nb = (long int)n;
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	i = get_len(n);
	str[i] = '\0';
	if (nb == 0)
		str[0] = 0 + '0';
	while (nb > 0)
	{
		i--;
		str[i] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}
