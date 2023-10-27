/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:51:37 by dabdygal          #+#    #+#             */
/*   Updated: 2023/10/27 19:31:15 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

static void	print_stack(t_arg **a)
{
	t_arg	*tmp;

	if (!a || !*a)
		return ;
	tmp = NULL;
	while (tmp != *a)
	{
		if (!tmp)
			tmp = *a;
		printf("%i\n", tmp->arg);
		tmp = tmp->next;
	}
}

static void	free_all(t_arg **a, t_arg **b)
{
	if (a)
	{
		if (*a)
			free_stack(a);
		free(a);
	}
	if (b)
	{
		if (*b)
			free_stack(b);
		free(b);
	}
}

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
	t_arg	**a;
	t_arg	**b;

	if (argc < 2)
	{
		ft_putstr_fd(ERR_MSG, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	a = (t_arg **) malloc(sizeof(t_arg **));
	b = (t_arg **) malloc(sizeof(t_arg **));
	if (!a || !b || !init_stacks(argc, argv, a, b))
	{
		ft_putstr_fd(ERR_MSG, STDERR_FILENO);
		free_all(a, b);
		return (EXIT_FAILURE);
	}
	print_stack(a);
	free_all(a, b);
	return (EXIT_SUCCESS);
}
