/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourre <cbourre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:27:14 by cbourre           #+#    #+#             */
/*   Updated: 2023/03/06 15:15:38 by cbourre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>

# define TRUE 1
# define FALSE 0

typedef struct s_arg
{
	int				data;
	int				index;
	struct s_arg	*next;
}		t_arg;

// args_checker
void	args_checker(int argc, char **argv);

// check_if
int		check_if_char(char *str);
void	check_if_int(char **arg, int i, long tmp, int argc);
int		check_if_argnum(char *arg);
int		check_if_argdup(char **argv, int i, int num);

// error_message
void	m_error(void);

// find_num
int		find_min_arg(t_arg **stack, int i);
t_arg	*find_next_min(t_arg **stack);
int		find_worthy_path(t_arg **stack, int index);
int		find_max_bits(t_arg **stack);

// ft_free
void	ft_free(char **str);
void	ft_free_arg(int argc, char **arg);
void	free_stack(t_arg **stack);

// ft_sorting
int		sorted_stack(t_arg **stack_a);
void	stack_sorting(t_arg **stack_a, t_arg **stack_b);
void	little_sorting(t_arg **stack_a, t_arg **stack_b);
void	radix_sorting(t_arg **stack_a, t_arg **stack_b);

// little_sorting
void	sort_3_args(t_arg **stack_a);
void	sort_4_args(t_arg **stack_a, t_arg **stack_b);
void	sort_5_args(t_arg **stack_a, t_arg **stack_b);

// normalise
void	args_in_stack(t_arg **stack, int argc, char **argv);
void	normalise(t_arg **stack);

// operations - ft_swap
int		ft_swap(t_arg **stack);
int		sa(t_arg **stack_a);
int		sb(t_arg **stack_b);
int		ss(t_arg **stack_a, t_arg **stack_b);

// operations - ft_push
int		ft_push(t_arg **stack_two, t_arg **stack_one);
int		pa(t_arg **stack_a, t_arg **stack_b);
int		pb(t_arg **stack_a, t_arg **stack_b);

// operations - ft_rotate
int		ft_rotate(t_arg **stack);
int		ra(t_arg **stack_a);
int		rb(t_arg **stack_b);
int		rr(t_arg **stack_a, t_arg **stack_b);

// operations - ft_reverse_rotate
int		ft_reverse_rotate(t_arg **stack);
int		rra(t_arg **stack_a);
int		rrb(t_arg **stack_b);
int		rrr(t_arg **stack_a, t_arg **stack_b);

// lst functions
int		ftps_lstsize(t_arg *lst);
t_arg	*ftps_lstnew(int data);
void	ftps_lstadd_back(t_arg **lst, t_arg *new);
t_arg	*ftps_lstlast(t_arg *lst);
t_arg	*ftps_penultimate(t_arg *lst);

#endif
