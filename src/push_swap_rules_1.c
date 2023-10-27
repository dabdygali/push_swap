/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rules_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:35:41 by dabdygal          #+#    #+#             */
/*   Updated: 2023/10/27 17:37:26 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_arg **a, t_arg **b)
{
	rotate(a);
	rotate(b);
	return ;
}

void	reverse_rotate(t_arg **x)
{
	if (*x && (*x)->next != *x)
		*x = (*x)->prev;
	return ;
}

void	rrr(t_arg **a, t_arg **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	return ;
}
