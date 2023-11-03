/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_push_b_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:20:30 by dabdygal          #+#    #+#             */
/*   Updated: 2023/11/03 09:58:40 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	copy_op(t_op dst[], t_op src[])
{
	dst[0] = src[0];
	dst[1] = src[1];
}

void	both_up(t_op ops[], int aup, int bup)
{
	ops[0].fun_ptr = rr;
	if (aup <= bup)
	{
		ops[0].qty = aup;
		ops[1].fun_ptr = rb;
		ops[1].qty = bup - aup;
	}
	else
	{
		ops[0].qty = bup;
		ops[1].fun_ptr = ra;
		ops[1].qty = aup - bup;
	}
}

void	both_down(t_op ops[], int adown, int bdown)
{
	ops[0].fun_ptr = rrr;
	if (adown <= bdown)
	{
		ops[0].qty = adown;
		ops[1].fun_ptr = rrb;
		ops[1].qty = bdown - adown;
	}
	else
	{
		ops[0].qty = bdown;
		ops[1].fun_ptr = rra;
		ops[1].qty = adown - bdown;
	}
}

void	aup_bdown(t_all *all, t_op ops[], int ap, int bp)
{
	t_op	tmp[2];

	ops[0].fun_ptr = ra;
	ops[0].qty = ap - 1;
	ops[1].fun_ptr = rrb;
	ops[1].qty = all->size_b - bp + 1;
	set_up_up(all, tmp, ap, bp);
	if (tmp[0].qty + tmp[1].qty < ops[0].qty + ops[1].qty)
		copy_op(ops, tmp);
	set_up_down(all, tmp, ap, bp);
	if (tmp[0].qty + tmp[1].qty < ops[0].qty + ops[1].qty)
		copy_op(ops, tmp);
	set_down_up(all, tmp, ap, bp);
	if (tmp[0].qty + tmp[1].qty < ops[0].qty + ops[1].qty)
		copy_op(ops, tmp);
	set_down_down(all, tmp, ap, bp);
	if (tmp[0].qty + tmp[1].qty < ops[0].qty + ops[1].qty)
		copy_op(ops, tmp);
}

void	adown_bup(t_all *all, t_op ops[], int ap, int bp)
{
	t_op	tmp[2];

	ops[0].fun_ptr = rra;
	ops[0].qty = all->size_a - ap + 1;
	ops[1].fun_ptr = rb;
	ops[1].qty = bp - 1;
	set_up_up(all, tmp, ap, bp);
	if (tmp[0].qty + tmp[1].qty < ops[0].qty + ops[1].qty)
		copy_op(ops, tmp);
	set_up_down(all, tmp, ap, bp);
	if (tmp[0].qty + tmp[1].qty < ops[0].qty + ops[1].qty)
		copy_op(ops, tmp);
	set_down_up(all, tmp, ap, bp);
	if (tmp[0].qty + tmp[1].qty < ops[0].qty + ops[1].qty)
		copy_op(ops, tmp);
	set_down_down(all, tmp, ap, bp);
	if (tmp[0].qty + tmp[1].qty < ops[0].qty + ops[1].qty)
		copy_op(ops, tmp);
}
