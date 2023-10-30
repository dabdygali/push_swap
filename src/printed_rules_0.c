/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printed_rules_0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:55:54 by dabdygal          #+#    #+#             */
/*   Updated: 2023/10/30 14:47:50 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <unistd.h>

void	sa(t_all *all)
{
	swap(all->a);
	ft_putstr_fd(SA_MSG, STDOUT_FILENO);
	return ;
}

void	sb(t_all *all)
{
	swap(all->b);
	ft_putstr_fd(SB_MSG, STDOUT_FILENO);
	return ;
}

void	ss(t_all *all)
{
	swap_swap(all->a, all->b);
	ft_putstr_fd(SS_MSG, STDOUT_FILENO);
	return ;
}

void	pa(t_all *all)
{
	push_a(all->a, all->b);
	if (all->size_b)
		all->size_b--;
	all->size_a++;
	ft_putstr_fd(PA_MSG, STDOUT_FILENO);
	return ;
}

void	pb(t_all *all)
{
	push_b(all->a, all->b);
	if (all->size_a)
		all->size_a--;
	all->size_b++;
	ft_putstr_fd(PB_MSG, STDOUT_FILENO);
	return ;
}
