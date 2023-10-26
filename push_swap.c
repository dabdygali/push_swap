/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:51:37 by dabdygal          #+#    #+#             */
/*   Updated: 2023/10/26 14:08:12 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

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
	t_stack	a;
	t_stack	b;

	if (!init_stacks(argc, argv, &a, &b))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
