/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_hexa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:38:26 by jsauvain          #+#    #+#             */
/*   Updated: 2022/06/01 13:26:13 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	low_hexa(unsigned int n, int i)
{
	if (n >= 16)
	{
		i = low_hexa(n / 16, i);
		i = low_hexa(n % 16, i);
	}
	else if (n < 16)
	{
		if (n % 16 <= 9)
			i += ft_putchar((n % 16) + '0');
		else if (n % 16 == 10)
			i += ft_putchar('a');
		else if (n % 16 == 11)
			i += ft_putchar('b');
		else if (n % 16 == 12)
			i += ft_putchar('c');
		else if (n % 16 == 13)
			i += ft_putchar('d');
		else if (n % 16 == 14)
			i += ft_putchar('e');
		else if (n % 16 == 15)
			i += ft_putchar('f');
	}
	return (i);
}
