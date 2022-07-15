/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:31:28 by jsauvain          #+#    #+#             */
/*   Updated: 2022/07/15 10:30:46 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	free_double(char **src)
{
	int	i;

	i = 0;
	while (i < strlen_d(src))
	{
		free(src[i]);
		i++;
	}
	free(src);
}

void	ft_free(t_stack *lst1, t_stack *lst2, t_op *lst_op)
{
	t_op	*tmp;
	t_stack	*tmp2;

	while (lst_op->next != 0)
	{
		tmp = lst_op->next;
		free(lst_op->src);
		free(lst_op);
		lst_op = tmp;
	}
	free(lst_op->src);
	free(lst_op);
	while (lst1->next != 0)
	{
		tmp2 = lst1->next;
		free(lst1);
		lst1 = tmp2;
	}
	free(lst1);
	free(lst2->next);
	free(lst2);
}
