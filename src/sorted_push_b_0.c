/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_push_b_0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:06:57 by dabdygal          #+#    #+#             */
/*   Updated: 2023/11/03 09:58:42 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static void	build_alg(t_all *all, t_op ops[], int ap, int bp)
{
	if (ap - 1 <= all->size_a - ap + 1)
	{
		if (bp - 1 <= all->size_b - bp + 1)
			both_up(ops, ap - 1, bp - 1);
		else
			aup_bdown(all, ops, ap, bp);
	}
	else
	{
		if (bp - 1 > all->size_b - bp + 1)
			both_down(ops, all->size_a - ap + 1, all->size_b - bp + 1);
		else
			adown_bup(all, ops, ap, bp);
	}
}

static int	find_bpos(t_all *all, int arg)
{
	int		i;
	t_arg	*tmp;

	i = 1;
	tmp = *all->b;
	while (i <= all->size_b)
	{
		if (arg > tmp->arg && arg < tmp->prev->arg)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (0);
}

static void	upgrade_alg(t_alg *alg, t_op new[], int arg, t_utils *u)
{
	t_op	*t;

	t = alg->ops;
	if (!t[0].fun_ptr || new[0].qty + new[1].qty < t[0].qty + t[1].qty)
	{
		t[0] = new[0];
		t[1] = new[1];
		alg->ismin = 0;
		alg->ismax = 0;
		if (arg < u->bmin)
			alg->ismin = 1;
		if (arg > u->bmax)
			alg->ismax = 1;
	}
}

static void	calc_cheap_push(t_all *all, t_utils *u, t_alg *alg)
{
	t_op	tmp[2];
	t_arg	*a;
	int		i;

	tmp[0].fun_ptr = NULL;
	tmp[0].qty = 0;
	tmp[1].fun_ptr = NULL;
	tmp[1].qty = 0;
	a = *all->a;
	i = 1;
	while (i <= all->size_a)
	{
		if (a->arg > u->bmax || a->arg < u->bmin)
			build_alg(all, tmp, i, all->bmax_p);
		else
			build_alg(all, tmp, i, find_bpos(all, a->arg));
		upgrade_alg(alg, tmp, a->arg, u);
		i++;
		a = a->next;
	}
}

void	sorted_push_b(t_all *all, t_utils *u)
{
	t_alg	alg;

	alg.ops[0].fun_ptr = NULL;
	alg.ismax = 0;
	alg.ismin = 0;
	calc_cheap_push(all, u, &alg);
	do_ops(all, u, &alg);
}
