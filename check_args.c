/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:31:54 by jsauvain          #+#    #+#             */
/*   Updated: 2022/06/11 18:12:47 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int	one_argument(char **dst)
{
	int		i;
	int		j;

	j = 0;
	while (dst[j])
	{
		i = 0;
		while (dst[j][i])
		{
			if ((strlen_single(dst[j]) > 10
					|| (dst[j][i] < '0')
				|| (dst[j][i] > '9'))
				&& (dst[j][i] != '-'))
				return (1);
			i++;
		}
		if ((dst[j][i] == 0 && i == 0)
			|| (ft_atol(dst[j]) > 2147483647)
			|| (ft_atol(dst[j]) < -2147483648))
			return (1);
		j++;
	}
	return (0);
}

int	many_arguments(char **argv)
{
	int	i;
	int	j;

	j = 1;
	while (argv[j])
	{
		i = 0;
		if (argv[j][i] == '-')
			i++;
		while (argv[j][i])
		{
			if ((argv[j][i] < '0' || argv[j][i] > '9'))
				return (1);
			i++;
		}
		if ((argv[j][i] == 0 && i == 0)
				|| (argv[j][0] != '-' && i >= 11)
			|| (argv[j][0] == '-' && i >= 12)
			|| (ft_atol(argv[j]) > 2147483647)
			|| (ft_atol(argv[j]) < -2147483648))
			return (1);
		j++;
	}
	return (0);
}

int	check_args(char **argv)
{
	int		n;
	char	**dst;

	if ((strlen_double(argv)) == 1)
		return (1);
	else if ((strlen_double(argv) - 1) == 1 && check_space(argv[1]) == 1)
	{
		dst = ft_split(argv[1], ' ');
		n = one_argument(dst) + check_duplicate(dst);
		free_double(dst);
		return (n);
	}
	n = many_arguments(argv) + check_duplicate(argv + 1);
	return (n);
}

int	check_duplicate(char **src)
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
