/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:13:39 by dabdygal          #+#    #+#             */
/*   Updated: 2023/11/03 09:57:44 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define ERR_MSG "Error\n"
# define SA_MSG "sa\n"
# define SB_MSG "sb\n"
# define SS_MSG "ss\n"
# define PA_MSG "pa\n"
# define PB_MSG "pb\n"
# define RA_MSG "ra\n"
# define RB_MSG "rb\n"
# define RR_MSG "rr\n"
# define RRA_MSG "rra\n"
# define RRB_MSG "rrb\n"
# define RRR_MSG "rrr\n"

typedef struct s_int_node
{
	struct s_int_node	*prev;
	struct s_int_node	*next;
	int					arg;
}	t_arg;

typedef struct s_all
{
	t_arg	**a;
	t_arg	**b;
	int		size_a;
	int		size_b;
	int		bmax_p;
}	t_all;

typedef struct s_op
{
	void	(*fun_ptr)(t_all *);
	int		qty;
}	t_op;

typedef struct s_alg
{
	t_op	ops[2];
	int		ismax;
	int		ismin;
}	t_alg;

typedef struct s_utils
{
	int		bmax;
	int		bmin;
}	t_utils;

int		init_stacks(int argc, char *argv[], t_arg **a, t_arg **b);
void	swap(t_arg	**x);
void	swap_swap(t_arg **a, t_arg **b);
void	push_a(t_arg **a, t_arg **b);
void	push_b(t_arg **a, t_arg **b);
void	rotate(t_arg **x);
void	rotate_rotate(t_arg **a, t_arg **b);
void	reverse_rotate(t_arg **x);
void	rev_rotate_rotate(t_arg **a, t_arg **b);
void	free_stack(t_arg **top);
void	free_strv(char **strv);
void	sa(t_all *all);
void	sb(t_all *all);
void	ss(t_all *all);
void	pa(t_all *all);
void	pb(t_all *all);
void	ra(t_all *all);
void	rb(t_all *all);
void	rr(t_all *all);
void	rra(t_all *all);
void	rrb(t_all *all);
void	rrr(t_all *all);
void	sort_stack_print(t_all *all);
void	free_all(t_arg **a, t_arg **b);
int		calc_stack_size(t_arg **x);
void	small_sort_print(t_all *all);
void	both_up(t_op ops[], int aup, int bup);
void	both_down(t_op ops[], int aup, int bup);
void	sorted_push_b(t_all *all, t_utils *u);
void	set_up_up(t_all *all, t_op ops[], int ap, int bp);
void	set_up_down(t_all *all, t_op ops[], int ap, int bp);
void	set_down_up(t_all *all, t_op ops[], int ap, int bp);
void	set_down_down(t_all *all, t_op ops[], int ap, int bp);
void	adown_bup(t_all *all, t_op ops[], int ap, int bp);
void	aup_bdown(t_all *all, t_op ops[], int ap, int bp);
void	do_ops(t_all *all, t_utils *u, t_alg *alg);
int		find_a_max(t_all *all);
void	align_a(t_all *all);
int		is_a_sorted(t_all *all);

#endif
