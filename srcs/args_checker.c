/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourre <cbourre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:33:25 by cbourre           #+#    #+#             */
/*   Updated: 2023/03/06 15:51:09 by cbourre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**ft_get_arg(int argc, char **argv, int *i)
{
	char	**arg;

	arg = NULL;
	if (argc == 2)
	{
		arg = ft_split(argv[1], ' ');
		if (arg[*i] == NULL)
			ft_free_arg(argc, arg);
	}
	else
	{
		*i = 1;
		arg = argv;
	}
	return (arg);
}

// check the arguments and put them in a tab
void	args_checker(int argc, char **argv)
{
	int		i;
	long	tmp;
	char	**arg;

	i = 0;
	arg = ft_get_arg(argc, argv, &i);
	while (arg[i])
	{
		if (check_if_char(arg[i]) == FALSE)
			ft_free_arg(argc, arg);
		tmp = ft_atol(arg[i]);
		check_if_int(arg, i, tmp, argc);
		i++;
	}
	if (argc == 2)
		ft_free(arg);
}
