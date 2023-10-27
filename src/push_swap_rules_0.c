/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_0.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:35:41 by dabdygal          #+#    #+#             */
/*   Updated: 2023/10/27 12:15:28 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	swap(t_arg	**x)
{
	int	tmp;

	if (!*x || (*x)->next == *x)
		return ;
	tmp = (*x)->arg;
	(*x)->arg = (*x)->next->arg;
	(*x)->next->arg = tmp;
	return ;
}

void	ss(t_arg **a, t_arg **b)
{
	swap(a);
	swap(b);
	return ;
}

void	pa(t_arg **a, t_arg **b)
{
	t_arg	*tmp;

	if (!*b)
		return ;
	tmp = *b;
	if ((*b)->next != *b)
	{
		(*b)->prev->next = (*b)->next;
		(*b)->next->prev = (*b)->prev;
		*b = (*b)->next;
	}
	else
		*b = NULL;
	if (!*a)
	{
		*a = tmp;
		(*a)->next = *a;
		(*a)->prev = *a;
	}
	else
	{
		(*a)->prev->next = tmp;
		(*a)->next->prev = tmp;
		*a = tmp;
	}
}

void	pb(t_arg **a, t_arg **b)
{
	t_arg	*tmp;

	if (!*a)
		return ;
	tmp = *a;
	if ((*a)->next != *a)
	{
		(*a)->prev->next = (*a)->next;
		(*a)->next->prev = (*a)->prev;
		*a = (*a)->next;
	}
	else
		*a = NULL;
	if (!*b)
	{
		*b = tmp;
		(*b)->next = *b;
		(*b)->prev = *b;
	}
	else
	{
		(*b)->prev->next = tmp;
		(*b)->next->prev = tmp;
		*b = tmp;
	}
}

void	rotate(t_arg **x)
{
	if (*x && (*x)->next != *x)
		*x = (*x)->next;
	return ;
}
