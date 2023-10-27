/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:13:39 by dabdygal          #+#    #+#             */
/*   Updated: 2023/10/27 18:30:20 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define ERR_MSG "Error\n"

typedef struct s_int_node
{
	struct s_int_node	*prev;
	struct s_int_node	*next;
	int					arg;
}	t_arg;

int		init_stacks(int argc, char *argv[], t_arg **a, t_arg **b);
void	swap(t_arg	**x);
void	ss(t_arg **a, t_arg **b);
void	pa(t_arg **a, t_arg **b);
void	pb(t_arg **a, t_arg **b);
void	rotate(t_arg **x);
void	rr(t_arg **a, t_arg **b);
void	reverse_rotate(t_arg **x);
void	rrr(t_arg **a, t_arg **b);
void	free_stack(t_arg **top);
void	free_strv(char **strv);

#endif
