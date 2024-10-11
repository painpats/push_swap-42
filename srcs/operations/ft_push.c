/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourre <cbourre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:57:37 by cbourre           #+#    #+#             */
/*   Updated: 2023/03/03 17:58:57 by cbourre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//pa, pb
int	ft_push(t_arg **stack_two, t_arg **stack_one)
{
	t_arg	*tmp;
	t_arg	*first_one;
	t_arg	*first_two;

	if (ftps_lstsize(*stack_one) == 0)
		return (1);
	first_one = *stack_one;
	first_two = *stack_two;
	tmp = first_one;
	first_one = first_one->next;
	*stack_one = first_one;
	if (!first_two)
	{
		first_two = tmp;
		first_two->next = NULL;
		*stack_two = first_two;
	}
	else
	{
		tmp->next = first_two;
		*stack_two = tmp;
	}
	return (0);
}

// Take the first element at the top of b and put it at the top of a
int	pa(t_arg **stack_a, t_arg **stack_b)
{
	if (ft_push(stack_a, stack_b) == 1)
		return (1);
	ft_putendl_fd("pa", 1);
	return (0);
}

// Take the first element at the top of a and put it at the top of b
int	pb(t_arg **stack_a, t_arg **stack_b)
{
	if (ft_push(stack_b, stack_a) == 1)
		return (1);
	ft_putendl_fd("pb", 1);
	return (0);
}
