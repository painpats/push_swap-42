/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourre <cbourre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:12:21 by cbourre           #+#    #+#             */
/*   Updated: 2023/03/06 15:30:20 by cbourre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// run push_swap
int	main(int argc, char **argv)
{
	t_arg	**stack_a;
	t_arg	**stack_b;

	args_checker(argc, argv);
	stack_a = (t_arg **)malloc(sizeof(t_arg));
	stack_b = (t_arg **)malloc(sizeof(t_arg));
	if (!stack_a || !stack_b)
		return (0);
	*stack_a = NULL;
	*stack_b = NULL;
	args_in_stack(stack_a, argc, argv);
	if (sorted_stack(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	stack_sorting(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
