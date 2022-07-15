/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:27:42 by jsauvain          #+#    #+#             */
/*   Updated: 2022/07/15 10:30:11 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int	check_space(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

t_stack	*initialization(char **argv, t_stack *lst1)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = lst1;
	lst1->next = ft_lstnew(ft_atol(argv[i]), 0);
	i++;
	while (i < strlen_d(argv))
	{
		lst1 = lst1->next;
		lst1->next = ft_lstnew(ft_atol(argv[i]), 0);
		i++;
	}
	lst1->next->next = ft_lstnew(0, 0);
	lst1 = tmp;
	lst1->indice = i;
	return (lst1);
}

int	ft_init(int argc, char **argv, t_stack *lst1, t_stack *lst2)
{
	char	**dst;
	int		i;

	if (argc == 2 && check_space(argv[1]))
	{
		dst = ft_split(argv[1], ' ');
		i = strlen_d(dst);
		lst1 = initialization(dst, lst1);
		lst2->next = ft_lstnew(0, 0);
		lst2->indice = 0;
		lst2->next->indice = 0;
		ft_sort_indice(lst1);
		free_double(dst);
		return (i);
	}
	lst1 = initialization(argv + 1, lst1);
	lst2->next = ft_lstnew(0, 0);
	lst2->indice = 0;
	lst2->next->indice = 0;
	ft_sort_indice(lst1);
	return (argc - 1);
}
