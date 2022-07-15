/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:36:12 by jsauvain          #+#    #+#             */
/*   Updated: 2022/07/15 10:35:37 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dst_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	char	*calloc;

	i = 0;
	calloc = malloc(nmemb * size);
	if (calloc == NULL)
		return (calloc);
	while (i < nmemb * size)
	{
		calloc[i] = '1';
		i++;
	}
	return (calloc);
}

char	**dst_malloc(char **dst, char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			j++;
		i++;
	}
	dst = malloc((j + 1) * sizeof(char *));
	if (dst == NULL)
		return (NULL);
	dst[j] = 0;
	return (dst);
}

char	*dst_arg_malloc(char *dst, char const *s, char c, int i)
{
	int	j;

	j = 0;
	while (s[i] != c && s[i])
	{	
		i++;
		j++;
	}
	if (j == 0)
		return (NULL);
	else
	{
		dst = ft_dst_calloc(j + 1, sizeof(char));
		dst[j] = '\0';
	}
	return (dst);
}

char	**assign_dst(char **dst, char const *s, char c)
{
	int	i;
	int	j;

	j = 0;
	while (*s)
	{
		i = 0;
		while (*s == c)
			s++;
		while (*s != c && *s)
		{	
			dst[j][i++] = *s;
			s++;
		}
		j++;
	}
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dst = NULL;
	dst = dst_malloc(dst, s, c);
	if (dst == NULL)
		return (dst);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{	
			dst[j] = dst_arg_malloc(dst[j], s, c, i);
			if (dst[j] == NULL || dst[0] == 0)
				return (dst);
			j++;
			i += strlen_s(dst[j - 1]);
		}
	}
	dst = assign_dst(dst, s, c);
	return (dst);
}
