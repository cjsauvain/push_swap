/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:01:56 by jsauvain          #+#    #+#             */
/*   Updated: 2022/06/01 13:26:31 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	to_find(const char *format, char c, va_list arg)
{
	int	i;

	i = 0;
	while (*format)
	{
		if (*format == c)
		{
			i += ft_formatting(format, arg);
			format += 2;
		}
		else
		{
			i += ft_putchar(*format);
			format++;
		}
	}
	return (i);
}
