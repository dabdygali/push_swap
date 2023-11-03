/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rules_0.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:35:41 by dabdygal          #+#    #+#             */
/*   Updated: 2023/11/02 14:56:36 by dabdygal         ###   ########.fr       */
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

void	swap_swap(t_arg **a, t_arg **b)
{
	swap(a);
	swap(b);
	return ;
}

void	push_a(t_arg **a, t_arg **b)
{
	t_arg	*tmp;

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
		tmp->next = *a;
		tmp->prev = (*a)->prev;
		(*a)->prev->next = tmp;
		(*a)->prev = tmp;
		*a = tmp;
	}
}

void	push_b(t_arg **a, t_arg **b)
{
	t_arg	*tmp;

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
		tmp->next = *b;
		tmp->prev = (*b)->prev;
		(*b)->prev->next = tmp;
		(*b)->prev = tmp;
		*b = tmp;
	}
}

void	rotate(t_arg **x)
{
	if (*x && (*x)->next != *x)
		*x = (*x)->next;
	return ;
}
