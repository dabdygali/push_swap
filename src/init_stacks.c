/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:23:45 by dabdygal          #+#    #+#             */
/*   Updated: 2023/10/30 14:53:03 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

int	calc_stack_size(t_arg **x)
{
	t_arg	*tmp;
	int		size;

	if (!x || !*x)
		return (0);
	size = 1;
	tmp = *x;
	while (tmp->next != *x)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

static int	no_duplicates(t_arg *top)
{
	t_arg	*tmp;
	t_arg	*tmp1;

	if (!top)
		return (0);
	tmp = NULL;
	while (tmp != top)
	{
		if (!tmp)
			tmp = top;
		tmp1 = top;
		while (tmp1 != tmp)
		{
			if (tmp1->arg == tmp->arg)
				return (0);
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

static int	append_node(t_arg **top, char *str)
{
	t_arg	*tmp;

	if (!*top)
	{
		*top = (t_arg *) malloc(sizeof(t_arg));
		if (!*top)
			return (0);
		(*top)->arg = ft_atoi(str);
		(*top)->next = *top;
		(*top)->prev = *top;
	}
	else
	{
		tmp = *top;
		while (tmp->next != *top)
			tmp = tmp->next;
		tmp->next = (t_arg *) malloc(sizeof(t_arg));
		if (!tmp->next)
			return (0);
		tmp->next->arg = ft_atoi(str);
		tmp->next->prev = tmp;
		tmp->next->next = *top;
		(*top)->prev = tmp->next;
	}
	return (1);
}

static int	add_arg(t_arg **a, char *str)
{
	if (!ft_str_is_int(str) || !append_node(a, str) || !no_duplicates(*a))
	{
		free_stack(a);
		return (0);
	}
	return (1);
}

int	init_stacks(int argc, char *argv[], t_arg **a, t_arg **b)
{
	int		i;
	int		j;
	char	**strv;

	*b = NULL;
	*a = NULL;
	i = 1;
	while (i < argc)
	{
		strv = ft_split_wspace(argv[i]);
		if (!strv)
			return (0);
		j = 0;
		while (strv[j])
		{
			if (!add_arg(a, strv[j++]))
			{
				free_strv(strv);
				return (0);
			}
		}
		free_strv(strv);
		i++;
	}
	return (1);
}
