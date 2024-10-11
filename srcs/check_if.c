/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourre <cbourre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:15:49 by cbourre           #+#    #+#             */
/*   Updated: 2023/03/06 15:29:32 by cbourre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_zero(char *arg)
{
	int	i;

	i = 0;
	if (arg[0] == '-' || arg[0] == '+')
		i++;
	while (arg[i] == '0')
		i++;
	return (i);
}

int	check_if_char(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (FALSE);
	while (str[i] && !ft_isdigit(str[i]))
		i++;
	if (i >= 2)
		return (FALSE);
	if (!str[i])
		return (FALSE);
	else if (ft_isdigit(str[i]))
		return (TRUE);
	else
		return (TRUE);
}

void	check_if_int(char **arg, int i, long tmp, int argc)
{
	if (check_if_argnum(arg[i]) == FALSE)
		ft_free_arg(argc, arg);
	if (check_if_argdup(arg, i, tmp))
		ft_free_arg(argc, arg);
	if (arg[i][0] == '-' && ft_strlen(arg[i] + count_zero(arg[i])) > 11)
		ft_free_arg(argc, arg);
	else if (ft_strlen(arg[i] + count_zero(arg[i])) > 10)
		ft_free_arg(argc, arg);
	if (tmp < -2147483648 || tmp > 2147483647)
		ft_free_arg(argc, arg);
}

// check if arg == numeral
int	check_if_argnum(char *arg)
{
	int	i;

	i = 0;
	if (arg[0] == '-' || arg[0] == '+')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

// check if arg have a duplicate
int	check_if_argdup(char **argv, int i, int num)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}
