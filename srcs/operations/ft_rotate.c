/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourre <cbourre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:58:41 by cbourre           #+#    #+#             */
/*   Updated: 2023/03/05 19:33:22 by cbourre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//ra, rb, rr
int	ft_rotate(t_arg **stack)
{
	t_arg	*first;
	t_arg	*last;

	if (ftps_lstsize(*stack) < 2)
		return (1);
	first = *stack;
	last = ftps_lstlast(first);
	*stack = first->next;
	first->next = NULL;
	last->next = first;
	return (0);
}

// Shift up all elements of stack a by 1
int	ra(t_arg **stack_a)
{
	if (ft_rotate(stack_a) == 1)
		return (1);
	ft_putendl_fd("ra", 1);
	return (0);
}

// Shift up all elements of stack b by 1
int	rb(t_arg **stack_b)
{
	if (ft_rotate(stack_b) == 1)
		return (1);
	ft_putendl_fd("rb", 1);
	return (0);
}

// ra and rb at the same time
int	rr(t_arg **stack_a, t_arg **stack_b)
{
	if ((ftps_lstsize(*stack_a) < 2) || (ftps_lstsize(*stack_b) < 2))
		return (1);
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_putendl_fd("rr", 1);
	return (0);
}
