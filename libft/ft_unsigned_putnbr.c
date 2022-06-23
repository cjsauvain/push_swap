/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_putnbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:35:30 by jsauvain          #+#    #+#             */
/*   Updated: 2022/06/01 13:26:04 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_unsigned_putnbr(unsigned int n, int i)
{
	if (n >= 10)
		i = ft_unsigned_putnbr(n / 10, i);
	i += ft_putchar((n % 10) + '0');
	return (i);
}
