/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourre <cbourre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:30:44 by cbourre           #+#    #+#             */
/*   Updated: 2023/03/06 12:10:37 by cbourre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// check if the args are already sorted or not
int	sorted_stack(t_arg **stack)
{
	t_arg	*first;

	first = *stack;
	while (first && first->next)
	{
		if (first->data > first->next->data)
			return (FALSE);
		first = first->next;
	}
	return (TRUE);
}

// function that is going to choose the worthyest sorting
void	stack_sorting(t_arg **stack_a, t_arg **stack_b)
{
	if (ftps_lstsize(*stack_a) < 6)
		little_sorting(stack_a, stack_b);
	else
		radix_sorting(stack_a, stack_b);
}

// sorting the stack if arg == 3 || 4 || 5
void	little_sorting(t_arg **stack_a, t_arg **stack_b)
{
	int	num_arg;

	if (sorted_stack(stack_a) || ftps_lstsize(*stack_a) == 0
		|| ftps_lstsize(*stack_a) == 1)
		return ;
	num_arg = ftps_lstsize(*stack_a);
	if (num_arg == 2)
		sa(stack_a);
	else if (num_arg == 3)
		sort_3_args(stack_a);
	else if (num_arg == 4)
		sort_4_args(stack_a, stack_b);
	else if (num_arg == 5)
		sort_5_args(stack_a, stack_b);
}

// sorting the stack with radix
void	radix_sorting(t_arg **stack_a, t_arg **stack_b)
{
	t_arg	*first;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	first = *stack_a;
	size = ftps_lstsize(first);
	max_bits = find_max_bits(&first);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			first = *stack_a;
			if (((first->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ftps_lstsize(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}
