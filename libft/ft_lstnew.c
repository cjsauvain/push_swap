/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 15:44:28 by jsauvain          #+#    #+#             */
/*   Updated: 2022/06/09 15:55:22 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_lstnew(int element, int i)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return (new);
	new->element = element;
	new->indice = i;
	new->next = NULL;
	return (new);
}

t_op	*ft_lstnew_string(char *src)
{
	t_op	*new;

	new = malloc(sizeof(t_op));
	if (new == NULL)
		return (new);
	new->src = ft_strdup(src);
	new->next = NULL;
	return (new);
}
