/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourre <cbourre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:56:05 by cbourre           #+#    #+#             */
/*   Updated: 2023/03/03 19:37:47 by cbourre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//sa, sb, ss
int	ft_swap(t_arg **stack)
{
	int		i_tmp;
	int		data_tmp;
	t_arg	*first;
	t_arg	*next;

	if (ftps_lstsize(*stack) < 2)
		return (1);
	first = *stack;
	next = first->next;
	if (!first && !next)
		m_error();
	i_tmp = first->index;
	data_tmp = first->data;
	next->index = i_tmp;
	next->data = data_tmp;
	return (0);
}

// Swap the first 2 elements at the top of stack a
int	sa(t_arg **stack_a)
{
	if (ft_swap(stack_a) == 1)
		return (1);
	ft_putendl_fd("sa", 1);
	return (0);
}

// Swap the first 2 elements at the top of stack b
int	sb(t_arg **stack_b)
{
	if (ft_swap(stack_b) == 1)
		return (1);
	ft_putendl_fd("sb", 1);
	return (0);
}

// Swap the first 2 elements at the top of stack b
int	ss(t_arg **stack_a, t_arg **stack_b)
{
	if ((ftps_lstsize(*stack_a) < 2) || (ftps_lstsize(*stack_b) < 2))
		return (1);
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_putendl_fd("ss", 1);
	return (0);
}
