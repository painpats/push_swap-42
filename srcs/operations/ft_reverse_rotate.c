/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourre <cbourre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:00:06 by cbourre           #+#    #+#             */
/*   Updated: 2023/03/04 18:03:11 by cbourre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//rra, rrb, rrr
int	ft_reverse_rotate(t_arg **stack)
{
	t_arg	*first;
	t_arg	*last;

	if (ftps_lstsize(*stack) < 2)
		return (1);
	first = *stack;
	last = ftps_lstlast(first);
	ftps_penultimate(*stack)->next = NULL;
	last->next = first;
	*stack = last;
	return (0);
}

// Shift down all elements of stack a by 1
int	rra(t_arg **stack_a)
{
	if (ft_reverse_rotate(stack_a) == 1)
		return (1);
	ft_putendl_fd("rra", 1);
	return (0);
}

// Shift down all elements of stack b by 1
int	rrb(t_arg **stack_b)
{
	if (ft_reverse_rotate(stack_b) == 1)
		return (1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

// rra and rrb at the same time
int	rrr(t_arg **stack_a, t_arg **stack_b)
{
	if ((ftps_lstsize(*stack_a) < 2) || (ftps_lstsize(*stack_b) < 2))
		return (1);
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	ft_putendl_fd("rrr", 1);
	return (0);
}
