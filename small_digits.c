/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:02:23 by jsauvain          #+#    #+#             */
/*   Updated: 2022/06/11 18:42:00 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	correct_indices(t_stack *lst)
{
	lst->indice--;
	lst = lst->next;
	while (lst->next != 0)
	{
		lst->indice--;
		lst = lst->next;
	}
}

void	sorting(t_stack *lst1, t_stack *lst2, t_op *lst_op)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	tmp = lst1->next;
	while (tmp->indice != 1)
	{
		tmp = tmp->next;
		i++;
	}
	if (i > (lst1->indice / 2))
	{
		while (lst1->next->indice != 1)
			reverse_rotate(lst1, lst_op, 0);
		push(lst1, lst2, lst_op, 0);
		lst2->indice++;
	}
	else
	{
		while (lst1->next->indice != 1)
			rotate(lst1, lst_op, 0);
		push(lst1, lst2, lst_op, 0);
		lst2->indice++;
	}
	correct_indices(lst1);
}

void	sort_three_digits(t_stack *lst1, t_op *lst_op)
{
	if (check_order(lst1) == 0)
		return ;
	if (lst1->next->indice == 1)
	{
		reverse_rotate(lst1, lst_op, 0);
		swap(lst1, lst_op, 0);
	}
	else if (lst1->next->indice == 2)
	{
		if (lst1->next->next->indice == 3)
			reverse_rotate(lst1, lst_op, 0);
		else
			swap(lst1, lst_op, 0);
	}
	else
	{
		if (lst1->next->next->indice == 1)
			rotate(lst1, lst_op, 0);
		else
		{
			swap(lst1, lst_op, 0);
			reverse_rotate(lst1, lst_op, 0);
		}
	}
}

void	sort_small_digits(t_stack *lst1, t_stack *lst2, t_op *lst_op)
{
	if (lst1->indice == 2)
	{
		if (lst1->next->indice == 2)
			swap(lst1, lst_op, 0);
		return ;
	}
	if (lst1->indice == 3)
	{
		sort_three_digits(lst1, lst_op);
		while (lst2->indice)
		{
			push(lst2, lst1, lst_op, 1);
			lst2->indice--;
		}
		return ;
	}
	sorting(lst1, lst2, lst_op);
	sort_small_digits(lst1, lst2, lst_op);
}
