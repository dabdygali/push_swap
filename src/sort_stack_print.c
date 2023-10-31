/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:31:32 by dabdygal          #+#    #+#             */
/*   Updated: 2023/10/31 14:41:46 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	small_sort_print(t_all *all)
{
	int	n1;
	int	n2;
	int	n3;

	if (all->size_a == 1)
		return ;
	n1 = (*all->a)->arg;
	n2 = (*all->a)->next->arg;
	if (all->size_a == 3)
	{
		n3 = (*all->a)->prev->arg;
		if (n1 > n2 && n1 > n3)
			ra(all);
		if (n1 < n2 && n2 > n3)
			rra(all);
	}
	if ((*all->a)->arg > (*all->a)->next->arg)
		sa(all);
}

void	sort_stack_print(t_all *all)
{
	t_utils	u;

	pb(all);
	u.bmax = (*all->b)->arg;
	u.bmax_p = 1;
	if (all->size_a > 3)
	{
		pb(all);
		if ((*all->b)->arg > (*all->b)->next->arg)
			u.bmax = (*all->b)->arg;
		else
			u.bmax_p = 2;
	}
	while (all->size_a > 3)
		sort_push_b;
	small_sort_print;
	sort_push_a;
}
