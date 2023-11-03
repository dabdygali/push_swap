/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:31:32 by dabdygal          #+#    #+#             */
/*   Updated: 2023/11/03 09:58:22 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	find_a_max(t_all *all)
{
	int		i;
	t_arg	*tmp;
	int		max;
	int		x;

	i = 1;
	x = 1;
	tmp = *all->a;
	max = (*all->a)->arg;
	while (i <= all->size_a)
	{
		if (tmp->arg > max)
		{
			max = tmp->arg;
			x = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (x);
}

static int	find_apos(t_all *all)
{
	int		i;
	t_arg	*tmp;
	int		x;

	i = 1;
	tmp = *all->a;
	while (i <= all->size_a)
	{
		if ((*all->b)->arg < tmp->arg && (*all->b)->arg > tmp->prev->arg)
			return (i);
		i++;
		tmp = tmp->next;
	}
	x = find_a_max(all);
	if (x == all->size_a)
		return (1);
	return (x + 1);
}

static void	fill_a(t_all *all)
{
	int	pos;
	int	i;

	while (all->size_b)
	{
		pos = find_apos(all);
		if (pos - 1 <= all->size_a - pos + 1)
		{
			i = pos - 1;
			while (i-- > 0)
				ra(all);
		}
		else
		{
			i = all->size_a - pos + 1;
			while (i-- > 0)
				rra(all);
		}
		pa(all);
	}
}

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
	all->bmax_p = 1;
	if (all->size_a > 3)
	{
		pb(all);
		if ((*all->b)->arg > (*all->b)->next->arg)
		{
			u.bmax = (*all->b)->arg;
			u.bmin = (*all->b)->next->arg;
		}
		else
		{
			all->bmax_p = 2;
			u.bmin = (*all->b)->arg;
		}
	}
	while (all->size_a > 3)
		sorted_push_b(all, &u);
	small_sort_print(all);
	fill_a(all);
	align_a(all);
}
