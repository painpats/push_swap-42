/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourre <cbourre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:30:56 by cbourre           #+#    #+#             */
/*   Updated: 2023/03/04 16:08:18 by cbourre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ftps_lstsize(t_arg *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

t_arg	*ftps_lstnew(int data)
{
	t_arg	*tmp;

	tmp = malloc(sizeof(t_list));
	if (tmp)
	{
		tmp->data = data;
		tmp->index = 0;
		tmp->next = NULL;
	}
	return (tmp);
}

void	ftps_lstadd_back(t_arg **lst, t_arg *new)
{
	t_arg	*tmp;

	if (!lst || !*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

t_arg	*ftps_lstlast(t_arg *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

t_arg	*ftps_penultimate(t_arg *lst)
{
	t_arg	*value;
	t_arg	*last;

	value = NULL;
	last = ftps_lstlast(lst);
	while (lst != last)
	{
		value = lst;
		lst = lst->next;
	}
	return (value);
}
