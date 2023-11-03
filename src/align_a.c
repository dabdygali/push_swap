/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 08:44:23 by dabdygal          #+#    #+#             */
/*   Updated: 2023/11/03 12:08:48 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	align_a(t_all *all)
{
	int	pos;

	pos = find_a_max(all);
	if (pos == all->size_a)
		pos = 1;
	else
		pos++;
	if (pos - 1 <= all->size_a - pos + 1)
	{
		while (pos - 1 > 0)
		{
			ra(all);
			pos--;
		}
	}
	else
	{
		while (all->size_a - pos + 1 > 0)
		{
			rra(all);
			pos++;
		}
	}
}

int	is_a_sorted(t_all *all)
{
	t_arg	*tmp;

	if (!all || !*all->a)
		return (0);
	tmp = NULL;
	while (tmp != *all->a)
	{
		if (!tmp)
			tmp = *all->a;
		if (tmp->arg > tmp->next->arg && tmp->next != *all->a)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
