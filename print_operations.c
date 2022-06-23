/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:46:02 by jsauvain          #+#    #+#             */
/*   Updated: 2022/06/11 14:32:45 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	get_operations(t_op *lst_op, char *src)
{
	t_op	*tmp;

	tmp = lst_op;
	while (tmp->next != 0)
		tmp = tmp->next;
	tmp->next = ft_lstnew_string(src);
}

int	ft_cmp(char *src, char *str)
{
	if (strlen_single(src) == 2 && strlen_single(str) == 2)
	{
		if (src[0] == str[0] && src[1] != str[1] && src[0] == 'p')
			return (1);
		else if (src[0] == str[0] && src[1] == str[1] && src[0] == 's')
			return (1);
	}
	else if (src[0] == str[0] && src[0] == 'r'
		&& (src[1] == str[2] || src[2] == str[1]))
		return (1);
	return (0);
}

void	print_operations(t_stack *lst1, t_stack *lst2, t_op *lst_op)
{
	t_op	*tmp;

	tmp = lst_op;
	while (tmp->next->next != 0)
	{
		if (ft_cmp(tmp->next->src, tmp->next->next->src) == 1)
		{
			tmp->next = tmp->next->next->next;
			tmp = lst_op;
		}
		else
			tmp = tmp->next;
	}
	tmp = lst_op->next;
	while (tmp->next != 0)
	{
		ft_printf("%s\n", tmp->src);
		tmp = tmp->next;
	}
	ft_printf("%s\n", tmp->src);
	ft_free(lst1, lst2, lst_op);
}
