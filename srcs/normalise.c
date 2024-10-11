/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourre <cbourre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:50:52 by cbourre           #+#    #+#             */
/*   Updated: 2023/03/06 12:12:11 by cbourre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// put the args in the stack
void	args_in_stack(t_arg **stack, int argc, char **argv)
{
	t_arg	*new;
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new = ftps_lstnew(ft_atoi(args[i]));
		ftps_lstadd_back(stack, new);
		i++;
	}
	normalise(stack);
	if (argc == 2)
		ft_free(args);
}

// normalise args means that the min_arg == 0 and the next one is 1, etc...
void	normalise(t_arg **stack)
{
	t_arg	*first;
	int		i;

	i = 0;
	first = find_next_min(stack);
	while (first)
	{
		first->index = i++;
		first = find_next_min(stack);
	}
}
