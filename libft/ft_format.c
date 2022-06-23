/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:37:35 by jsauvain          #+#    #+#             */
/*   Updated: 2022/06/01 13:25:02 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_hexa_ptr(va_list arg, int i)
{
	unsigned long long	ar;

	ar = va_arg(arg, unsigned long long);
	if (ar == 0)
		return (ft_putstr("(nil)"));
	i += ft_putstr("0x");
	i = put_hexa_ptr(ar, i);
	return (i);
}

int	ft_formatting(const char *str, va_list arg)
{
	int	i;

	i = 0;
	if (str[1] == 'c')
		i += ft_putchar(va_arg(arg, int));
	else if (str[1] == 's')
		i += ft_putstr(va_arg(arg, char *));
	else if (str[1] == 'p')
		i += ft_put_hexa_ptr(arg, i);
	else if (str[1] == 'i' || str[1] == 'd')
		i += ft_putnbr(va_arg(arg, int), i);
	else if (str[1] == 'u')
		i += ft_unsigned_putnbr(va_arg(arg, unsigned int), i);
	else if (str[1] == 'x')
		i += low_hexa(va_arg(arg, unsigned int), i);
	else if (str[1] == 'X')
		i += up_hexa(va_arg(arg, unsigned int), i);
	else if (str[1] == '%')
		i += ft_putchar('%');
	return (i);
}

int	ft_format(const char *str, va_list arg)
{
	int	i;

	i = 0;
	i += to_find(str, '%', arg);
	return (i);
}
