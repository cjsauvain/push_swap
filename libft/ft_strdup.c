/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:10:15 by jsauvain          #+#    #+#             */
/*   Updated: 2022/07/15 10:35:17 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s)
{
	int		i;
	char	*duplicate;

	i = 0;
	duplicate = malloc((strlen_s(s) + 1) * sizeof(char));
	if (duplicate == NULL)
		return (duplicate);
	while (i < strlen_s(s))
	{
		duplicate[i] = s[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}
