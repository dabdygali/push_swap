/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:51:37 by dabdygal          #+#    #+#             */
/*   Updated: 2023/11/03 12:11:34 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

/**
 * @brief A programm to sort a stack of integers.
 *
 * A program to sort a stack of integers using specific rules given at the
 * project subject.
 *
 * @param argc Arguments counter.
 * @param argv Arguments vector.
 * @return Returns EXIT_SUCCESS macro from stdlib.h. Mostly 0 when success
 * and 1 when program fails.
*/
int	main(int argc, char *argv[])
{
	t_all	all;

	all.a = (t_arg **) malloc(sizeof(t_arg *));
	all.b = (t_arg **) malloc(sizeof(t_arg *));
	*(all.a) = NULL;
	*(all.b) = NULL;
	if (!all.a || !all.b || !init_stacks(argc, argv, all.a, all.b) || !*all.a)
	{
		ft_putstr_fd(ERR_MSG, STDERR_FILENO);
		free_all(all.a, all.b);
		return (EXIT_FAILURE);
	}
	all.size_a = calc_stack_size(all.a);
	all.size_b = 0;
	if (is_a_sorted(&all))
		align_a(&all);
	else
	{
		if (all.size_a <= 3)
			small_sort_print(&all);
		else
			sort_stack_print(&all);
	}
	free_all(all.a, all.b);
	return (EXIT_SUCCESS);
}
