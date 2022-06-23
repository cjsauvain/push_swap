/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:47:25 by jsauvain          #+#    #+#             */
/*   Updated: 2022/06/09 17:16:14 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	swap(t_stack *lst, t_op *lst_op, int i)
{
	t_stack	tmp;

	if (lst)
	{
		tmp.element = lst->next->element;
		tmp.indice = lst->next->indice;
		lst->next->element = lst->next->next->element;
		lst->next->indice = lst->next->next->indice;
		lst->next->next->element = tmp.element;
		lst->next->next->indice = tmp.indice;
	}
	if (i == 0)
		get_operations(lst_op, "sa");
	else
		get_operations(lst_op, "sb");
}

void	push(t_stack *lst1, t_stack *lst2, t_op *lst_op, int i)
{
	t_stack	*tmp;

	tmp = lst1->next;
	lst1->next = lst1->next->next;
	tmp->next = lst2->next;
	lst2->next = tmp;
	lst2->next->next = tmp->next;
	if (i == 0)
		get_operations(lst_op, "pb");
	else
		get_operations(lst_op, "pa");
}

void	rotate(t_stack *lst, t_op *lst_op, int i)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = lst->next;
	tmp2 = lst;
	lst->next = lst->next->next;
	while (lst->next->next != 0)
		lst = lst->next;
	tmp->next = lst->next;
	lst->next = tmp;
	lst = tmp2;
	if (i == 0)
		get_operations(lst_op, "ra");
	else
		get_operations(lst_op, "rb");
}

void	reverse_rotate(t_stack *lst, t_op *lst_op, int i)
{
	t_stack	*tmp;
	t_stack	*temp;

	tmp = lst;
	while (lst->next->next->next != 0)
		lst = lst->next;
	temp = lst->next;
	lst->next = lst->next->next;
	temp->next = tmp->next;
	tmp->next = temp;
	lst = tmp;
	if (i == 0)
		get_operations(lst_op, "rra");
	else
		get_operations(lst_op, "rrb");
}
