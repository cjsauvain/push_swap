/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 08:28:32 by jsauvain          #+#    #+#             */
/*   Updated: 2022/07/18 08:31:44 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_op *lst)
{
	t_op	*tmp;

	tmp = lst;
	free(tmp->src);
	free(tmp->next->src);
	free(tmp->next);
	free(tmp);
}
