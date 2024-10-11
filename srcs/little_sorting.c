/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourre <cbourre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:30:50 by cbourre           #+#    #+#             */
/*   Updated: 2023/03/06 12:08:12 by cbourre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	end_sort_3(t_arg **stack_a, t_arg *first, int min)
{
	if (first->next->index == min)
		ra(stack_a);
	else
	{
		sa(stack_a);
		rra(stack_a);
	}
}

// sort the stack if arg == 3
void	sort_3_args(t_arg **stack_a)
{
	t_arg	*first;
	int		min;
	int		next_min;

	first = *stack_a;
	min = find_min_arg(stack_a, -1);
	next_min = find_min_arg(stack_a, min);
	if (sorted_stack(stack_a))
		return ;
	if (first->index == min && first->next->index != next_min)
	{
		ra(stack_a);
		sa(stack_a);
		rra(stack_a);
	}
	else if (first->index == next_min)
	{
		if (first->next->index == min)
			sa(stack_a);
		else
			rra(stack_a);
	}
	else
		end_sort_3(stack_a, first, min);
}

// sort the stack if arg == 4
void	sort_4_args(t_arg **stack_a, t_arg **stack_b)
{
	int	worthy_path;

	if (sorted_stack(stack_a))
		return ;
	worthy_path = find_worthy_path(stack_a, find_min_arg(stack_a, -1));
	if (worthy_path == 1)
		sa(stack_a);
	else if (worthy_path == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (worthy_path == 3)
		rra(stack_a);
	if (sorted_stack(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_3_args(stack_a);
	pa(stack_a, stack_b);
}

// sort the stack if arg == 5
void	sort_5_args(t_arg **stack_a, t_arg **stack_b)
{
	int	worthy_path;

	worthy_path = find_worthy_path(stack_a, find_min_arg(stack_a, -1));
	if (worthy_path == 1)
		ra(stack_a);
	else if (worthy_path == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (worthy_path == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (worthy_path == 4)
		rra(stack_a);
	if (sorted_stack(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_4_args(stack_a, stack_b);
	pa(stack_a, stack_b);
}
