/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:12:36 by jsauvain          #+#    #+#             */
/*   Updated: 2022/06/09 17:21:15 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	strlen_double(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	strlen_single(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
