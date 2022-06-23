/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:38:28 by jsauvain          #+#    #+#             */
/*   Updated: 2022/06/01 13:26:40 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	up_hexa(unsigned int n, int i)
{
	if (n >= 16)
	{
		i = up_hexa(n / 16, i);
		i = up_hexa(n % 16, i);
	}
	else if (n < 16)
	{
		if (n % 16 <= 9)
			i += ft_putchar((n % 16) + '0');
		else if (n % 16 == 10)
			i += ft_putchar('A');
		else if (n % 16 == 11)
			i += ft_putchar('B');
		else if (n % 16 == 12)
			i += ft_putchar('C');
		else if (n % 16 == 13)
			i += ft_putchar('D');
		else if (n % 16 == 14)
			i += ft_putchar('E');
		else if (n % 16 == 15)
			i += ft_putchar('F');
	}
	return (i);
}
