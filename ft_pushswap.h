/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:11:19 by jsauvain          #+#    #+#             */
/*   Updated: 2022/07/18 09:32:30 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H

# include "libft/libft.h"

//ft_pushswap.c
int		first_check(char **argv, t_stack *lst1, t_stack *lst2, t_op *lst);
int		second_check(char **argv, t_stack *lst1, t_stack *lst2, t_op *lst_op);
int		check_order(t_stack *lst1);

//ft_utils.c
int		check_space(char *argv);
t_stack	*initialization(char **argv, t_stack *lst1);
int		ft_init(int argc, char **argv, t_stack *lst1, t_stack *lst2);

//ft_sort.c
void	ft_sort_lst1(t_stack *lst1, t_stack *lst2, t_op *lst_op, int i);
void	ft_sort_lst2(t_stack *lst2, t_stack *lst1, t_op *lst_op, int i);
int		check_indice(t_stack *lst1);
void	ft_sort_indice(t_stack *lst1);
void	ft_sort(t_stack *lst1, t_stack *lst2, t_op *lst_op, int argc);

//swap_fonctions.c
void	swap(t_stack *lst, t_op *lst_op, int i);
void	push(t_stack *lst1, t_stack *lst2, t_op *lst_op, int i);
void	rotate(t_stack *lst, t_op *lst_op, int i);
void	reverse_rotate(t_stack *lst, t_op *lst_op, int i);

//small_digits.c
void	correct_indices(t_stack *lst);
void	sorting(t_stack *lst1, t_stack *lst2, t_op *lst_op);
void	sort_three_digits(t_stack *lst1, t_op *lst_op);
void	sort_small_digits(t_stack *lst1, t_stack *lst2, t_op *lst_op);

//check_args.c
int		checking(char **dst);
int		check_duplicates(char **src);
int		check_args_format(char **argv);
int		check_args(char **argv);

//print_operations.c
void	get_operations(t_op *lst_op, char *src);
int		ft_cmp(char *src, char *str);
void	print_operations(t_stack *lst1, t_stack *lst2, t_op *lst_op);

//ft_free.c
void	free_error(t_stack *lst1, t_stack *lst2, t_op *lst_op);
void	free_double(char **src);
void	ft_free(t_stack *lst1, t_stack *lst2, t_op *lst_op);

#endif
