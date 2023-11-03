/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ops_0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:44:41 by dabdygal          #+#    #+#             */
/*   Updated: 2023/11/02 17:18:52 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_up_up(t_all *all, t_op ops[], int ap, int bp)
{
	ops[0].fun_ptr = rr;
	if (ap <= bp)
	{
		ops[0].qty = ap - 1;
		ops[1].fun_ptr = rb;
		ops[1].qty = (bp - ops[0].qty % all->size_b) - 1;
	}
	else
	{
		ops[0].qty = bp - 1;
		ops[1].fun_ptr = ra;
		ops[1].qty = (ap - ops[0].qty % all->size_a) - 1;
	}
}

void	set_up_down(t_all *all, t_op ops[], int ap, int bp)
{
	int	x;

	ops[0].fun_ptr = rr;
	if (ap <= bp)
	{
		ops[0].qty = ap - 1;
		ops[1].fun_ptr = rrb;
		x = (bp - ops[0].qty % all->size_b) % all->size_b;
		ops[1].qty = all->size_b - x + 1;
	}
	else
	{
		ops[0].qty = bp - 1;
		ops[1].fun_ptr = rra;
		x = (ap - ops[0].qty % all->size_a) % all->size_a;
		ops[1].qty = all->size_a - x + 1;
	}
}

void	set_down_up(t_all *all, t_op ops[], int ap, int bp)
{
	ops[0].fun_ptr = rrr;
	if (ap <= bp)
	{
		ops[0].qty = all->size_a - ap + 1;
		ops[1].fun_ptr = rb;
		ops[1].qty = (bp + ops[0].qty % all->size_b) % all->size_b - 1;
	}
	else
	{
		ops[0].qty = all->size_b - bp + 1;
		ops[1].fun_ptr = ra;
		ops[1].qty = (ap + ops[0].qty % all->size_a) % all->size_a - 1;
	}
}

void	set_down_down(t_all *all, t_op ops[], int ap, int bp)
{
	int	x;

	ops[0].fun_ptr = rrr;
	if (ap <= bp)
	{
		ops[0].qty = all->size_a - ap + 1;
		ops[1].fun_ptr = rrb;
		x = (bp + ops[0].qty % all->size_b) % all->size_b;
		ops[1].qty = all->size_b - x + 1;
	}
	else
	{
		ops[0].qty = all->size_b - bp + 1;
		ops[1].fun_ptr = rra;
		x = (ap + ops[0].qty % all->size_a) % all->size_a;
		ops[1].qty = all->size_a - x + 1;
	}
}
