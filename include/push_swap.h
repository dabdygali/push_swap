/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:13:39 by dabdygal          #+#    #+#             */
/*   Updated: 2023/10/26 14:38:08 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define ERR_MSG "Error\n"

typedef struct s_stack
{
	int	*head;
	int	*stack;
	int	size;
}	t_stack;

int	init_stacks(int argc, char *argv[], t_stack *a, t_stack *b);

#endif
