/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:59:07 by jsauvain          #+#    #+#             */
/*   Updated: 2022/07/15 10:29:52 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int	check(char **argv, t_stack *lst1, t_stack *lst2, t_op *lst_op)
{
	if (strlen_d(argv) == 1)
		return (1);
	else if (check_args(argv) != 0)
	{
		ft_printf("Error\n");
		ft_free(lst1, lst2, lst_op);
		return (1);
	}
	else if (check_order(lst1) == 0)
	{
		ft_free(lst1, lst2, lst_op);
		return (1);
	}
	return (0);
}

int	check_order(t_stack *lst1)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	tmp = lst1->next;
	while (tmp->next != 0)
	{
		if (tmp->indice != i++)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*lst1;
	t_stack	*lst2;
	t_op	*lst_op;
	int		i;

	lst1 = malloc(sizeof(t_stack));
	lst2 = malloc(sizeof(t_stack));
	lst_op = ft_lstnew_string("\0");
	if (lst1 == NULL || lst2 == NULL || lst_op == NULL)
		return (0);
	if (argc > 1)
		i = ft_init(argc, argv, lst1, lst2);
	if (check(argv, lst1, lst2, lst_op) == 1)
		return (0);
	ft_sort(lst1, lst2, lst_op, i);
	print_operations(lst1, lst2, lst_op);
	return (0);
}
