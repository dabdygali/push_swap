/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_0.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:35:41 by dabdygal          #+#    #+#             */
/*   Updated: 2023/10/26 14:55:25 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *i)
{
	int	tmp;

	if (i->size < 2)
		return ;
	tmp = i->stack[0];
	i->stack[0] = i->stack[1];
	i->stack[1] = tmp;
	return ;
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	return ;
}

void	pa(t_stack *a, t_stack *b)
{
	if (!b->size)
		return ;
	a->stack--;
	a->stack[0] = b->stack[0];
	b->stack++;
	a->size++;
	b->size--;
}

void	pb(t_stack *a, t_stack *b)
{
	if (!a->size)
		return ;
	b->stack--;
	b->stack[0] = a->stack[0];
	a->stack++;
	a->size--;
	b->size++;
}
