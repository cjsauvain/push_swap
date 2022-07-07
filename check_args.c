/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:31:54 by jsauvain          #+#    #+#             */
/*   Updated: 2022/07/07 15:51:37 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int	checking(char **dst)
{
	int		i;
	int		j;

	j = 0;
	while (dst[j])
	{
		i = 0;
		if (strlen_single(dst[j]) > 10
			&& (dst[j][0] != '-' || dst[j][0] != '+'))
			return (1);
		if (dst[j][i] == '-' || dst[j][i] == '+')
			i++;
		while (dst[j][i])
		{
			if (dst[j][i] < '0' || dst[j][i] > '9')
				return (1);
			i++;
		}
		if ((i == 1 && (dst[j][0] == '-' || dst[j][0] == '+'))
			|| ft_atol(dst[j]) > 2147483647 || ft_atol(dst[j]) < -2147483648)
			return (1);
		j++;
	}
	return (0);
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

int	check_args_format(char **argv)
{
	int	i;
	
	if (strlen_double(argv) == 2)
	{
		i = 0;
		while (argv[1][i])
		{
			if (argv[1][i] == '"')
				return (1);
			i++;
		}
	}
	else if (strlen_double(argv) > 2)
	{
		i = 1;
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

	if ((strlen_double(argv)) == 1 || check_args_format(argv))
		return (1);
	else if (strlen_double(argv) == 2)
	{
		dst = ft_split(argv[1], ' ');
		n = checking(dst) + check_duplicate(dst);
		free_double(dst);
		return (n);
	}
	dst = argv + 1;
	return (checking(dst) + check_duplicate(dst));
}
