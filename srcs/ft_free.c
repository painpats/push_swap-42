/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourre <cbourre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:56:30 by cbourre           #+#    #+#             */
/*   Updated: 2023/03/06 15:19:28 by cbourre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_free_arg(int argc, char **arg)
{
	if (argc == 2)
		ft_free(arg);
	m_error();
}

void	free_stack(t_arg **stack)
{
	t_arg	*first;
	t_arg	*tmp;
	int		size;

	first = *stack;
	size = ftps_lstsize(*stack);
	while (size != 0)
	{
		tmp = first;
		first = first->next;
		size--;
		free(tmp);
	}
	free(stack);
}
