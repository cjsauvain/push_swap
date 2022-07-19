/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:31:54 by jsauvain          #+#    #+#             */
/*   Updated: 2022/07/18 09:06:14 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int	checking(char **dst)
{
	int		j;
	int		nb;
	char	*str;

	j = 0;
	while (dst[j])
	{
		nb = 0;
		str = ft_itoa(ft_atol(dst[j]));
		if (dst[j][0] == '-' || dst[j][0] == '+')
		{
			if (dst[j][0] == '+')
				nb = 1;
		}
		if (ft_strncmp(str, dst[j] + nb, strlen_s(dst[j])))
		{
			free(str);
			return (1);
		}
		j++;
		free(str);
	}
	return (0);
}

int	check_duplicates(char **src)
{
	int	i;
	int	j;

	i = 0;
	while (src[i])
	{
		j = i + 1;
		while (src[j])
		{
			if (ft_atol(src[j]) == ft_atol(src[i]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_args_format(char **argv)
{
	int	i;

	i = 1;
	if (strlen_d(argv) > 2)
	{
		while (argv[i])
		{
			if (check_space(argv[i]) == 1)
				return (1);
			i++;
		}
	}
	return (0);
}

int	check_args(char **argv)
{
	int		n;
	char	**dst;

	if (check_args_format(argv))
		return (1);
	else if (strlen_d(argv) == 2)
	{
		dst = ft_split(argv[1], ' ');
		n = checking(dst) + check_duplicates(dst);
		free_double(dst);
		return (n);
	}
	dst = argv + 1;
	return (checking(dst) + check_duplicates(dst));
}
