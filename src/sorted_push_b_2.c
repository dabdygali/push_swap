/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_push_b_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:04:02 by dabdygal          #+#    #+#             */
/*   Updated: 2023/11/02 15:34:05 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_ops(t_all *all, t_utils *u, t_alg *alg)
{
	while (alg->ops[0].qty > 0)
	{
		alg->ops[0].fun_ptr(all);
		alg->ops[0].qty--;
	}
	while (alg->ops[1].qty > 0)
	{
		alg->ops[1].fun_ptr(all);
		alg->ops[1].qty--;
	}
	pb(all);
	if (alg->ismax == 1)
	{
		u->bmax = (*all->b)->arg;
		all->bmax_p = 1;
		alg->ismax = 0;
	}
	if (alg->ismin == 1)
	{
		u->bmin = (*all->b)->arg;
		alg->ismin = 0;
	}
}
