/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:00:49 by jsauvain          #+#    #+#             */
/*   Updated: 2022/06/11 19:05:46 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_sort_lst1(t_stack *lst1, t_stack *lst2, t_op *lst_op, int i)
{
	int	l;
	int	j;

	l = 0;
	j = 0;
	while (l < lst1->indice)
	{
		if ((lst1->next->indice >> i & 1) == 0)
		{
			push(lst1, lst2, lst_op, 0);
			j++;
		}
		else
			rotate(lst1, lst_op, 0);
		l++;
	}
	lst1->indice -= j;
	lst2->indice += j;
}

void	ft_sort_lst2(t_stack *lst2, t_stack *lst1, t_op *lst_op, int i)
{
	int	l;
	int	j;

	l = 0;
	j = 0;
	while (l < lst2->indice)
	{
		if ((lst2->next->indice >> i & 1) == 1)
		{
			push(lst2, lst1, lst_op, 1);
			j++;
		}
		else
			rotate(lst2, lst_op, 1);
		l++;
	}
	lst2->indice -= j;
	lst1->indice += j;
}

int	check_indice(t_stack *lst1)
{
	t_stack	*tmp;

	tmp = lst1->next;
	while (tmp->next != 0)
	{
		if (tmp->indice == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_sort_indice(t_stack *lst1)
{
	t_stack	*tmp;
	t_stack	*cmp;
	int		i;

	i = 1;
	while (check_indice(lst1) == 0)
	{
		cmp = lst1->next;
		while (cmp->indice != 0 && cmp->next != 0)
			cmp = cmp->next;
		tmp = lst1->next->next;
		while (tmp->next != 0)
		{
			if (cmp->element > tmp->element && tmp->indice == 0)
				cmp = tmp;
			tmp = tmp->next;
		}
		cmp->indice = i++;
	}
}

void	ft_sort(t_stack *lst1, t_stack *lst2, t_op *lst_op, int argc)
{
	int		i;
	int		j;

	i = 31;
	j = 0;
	if (argc < 41)
		sort_small_digits(lst1, lst2, lst_op);
	else
	{
		while ((lst1->indice >> i & 1) == 0 && i)
			i--;
		while (j <= i)
		{
			ft_sort_lst1(lst1, lst2, lst_op, j);
			j++;
			if (j != i + 1)
				ft_sort_lst2(lst2, lst1, lst_op, j);
		}
		while (lst2->next != 0)
			push(lst2, lst1, lst_op, 1);
	}
}
