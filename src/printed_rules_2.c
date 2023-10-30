/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printed_rules_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:55:54 by dabdygal          #+#    #+#             */
/*   Updated: 2023/10/30 14:41:52 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <unistd.h>

void	rrr(t_all *all)
{
	rev_rotate_rotate(all->a, all->b);
	ft_putstr_fd(RRR_MSG, STDOUT_FILENO);
	return ;
}
