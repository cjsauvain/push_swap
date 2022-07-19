/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:06:57 by jsauvain          #+#    #+#             */
/*   Updated: 2022/07/18 08:30:43 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_stack
{
	int				indice;
	int				element;
	struct s_stack	*next;
}	t_stack;

typedef struct s_op
{
	int			indice;
	char		*src;
	struct s_op	*next;
}	t_op;

//libft
int			ft_strncmp(char *s1, char *s2, size_t n);
char		*ft_malloc(int n);
char		*ft_reverse(char *src);
char		*n_value(int n, char *src);
char		*ft_itoa(int n);
int			strlen_s(char *s);
int			strlen_d(char **s);
long int	ft_atol(const char *nptr);
char		*ft_strdup(char *s);
char		*ft_strjoin(char *s1, char *s2);
char		**ft_split(char const *s, char c);
void		ft_lstclear(t_op *lst);
t_stack		*ft_lstnew(int element, int i);
t_op		*ft_lstnew_string(char *src);

//ft_printf
int			ft_printf(const char *format, ...);
int			ft_formatting(const char *str, va_list arg);
int			ft_format(const char *format, va_list arg);
int			ft_putchar(char c);
int			ft_putstr(char *str);
int			ft_putnbr(int n, int i);
int			ft_unsigned_putnbr(unsigned int n, int i);
int			to_find(const char *format, char c, va_list arg);
int			low_hexa(unsigned int n, int i);
int			up_hexa(unsigned int n, int i);
int			put_hexa_ptr(unsigned long long ptr, int i);

#endif
