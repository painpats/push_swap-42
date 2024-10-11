/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourre <cbourre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:29:42 by cbourre           #+#    #+#             */
/*   Updated: 2023/03/06 12:12:04 by cbourre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// find the worthyest path to take (the quickest way to sort the stack)
int	find_worthy_path(t_arg **stack, int i)
{
	t_arg	*first;
	int		worthy_path;

	worthy_path = 0;
	first = *stack;
	while (first && (first->index != i))
	{
		worthy_path++;
		first = first->next;
	}
	return (worthy_path);
}

// find the smallest number of the stack
int	find_min_arg(t_arg **stack, int i)
{
	t_arg	*first;
	int		min_arg;

	first = *stack;
	min_arg = first->index;
	while (first->next)
	{
		first = first->next;
		if ((first->index < min_arg) && first->index != i)
			min_arg = first->index;
	}
	return (min_arg);
}

// find the next smallest number of the stack
t_arg	*find_next_min(t_arg **stack)
{
	t_arg	*first;
	t_arg	*min_arg;
	int		i;

	first = *stack;
	min_arg = NULL;
	i = 0;
	while (first)
	{
		if ((first->index == 0) && (!i || first->data < min_arg->data))
		{
			min_arg = first;
			i = 1;
		}
		first = first->next;
	}
	return (min_arg);
}

// find the big bits
int	find_max_bits(t_arg **stack)
{
	t_arg	*first;
	int		max;
	int		max_bits;

	first = *stack;
	max = first->index;
	max_bits = 0;
	while (first)
	{
		if (first->index > max)
			max = first->index;
		first = first->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}
