/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printed_rules_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:55:54 by dabdygal          #+#    #+#             */
/*   Updated: 2023/11/02 15:57:44 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <unistd.h>

void	ra(t_all *all)
{
	rotate(all->a);
	ft_putstr_fd(RA_MSG, STDOUT_FILENO);
	return ;
}

void	rb(t_all *all)
{
	rotate(all->b);
	if (all->bmax_p == 1)
		all->bmax_p = all->size_b;
	else
		all->bmax_p--;
	ft_putstr_fd(RB_MSG, STDOUT_FILENO);
	return ;
}

void	rr(t_all *all)
{
	rotate_rotate(all->a, all->b);
	if (all->bmax_p == 1)
		all->bmax_p = all->size_b;
	else
		all->bmax_p--;
	ft_putstr_fd(RR_MSG, STDOUT_FILENO);
	return ;
}

void	rra(t_all *all)
{
	reverse_rotate(all->a);
	ft_putstr_fd(RRA_MSG, STDOUT_FILENO);
	return ;
}

void	rrb(t_all *all)
{
	reverse_rotate(all->b);
	if (all->bmax_p == all->size_b)
		all->bmax_p = 1;
	else
		all->bmax_p++;
	ft_putstr_fd(RRB_MSG, STDOUT_FILENO);
	return ;
}
