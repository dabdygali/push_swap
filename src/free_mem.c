/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:39:32 by dabdygal          #+#    #+#             */
/*   Updated: 2023/10/30 11:24:14 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdlib.h>

void	free_stack(t_arg **top)
{
	t_arg	*tmp;
	t_arg	*buf;

	if (!*top)
		return ;
	tmp = (*top)->next;
	while (tmp != *top)
	{
		buf = tmp;
		tmp = tmp->next;
		free(buf);
	}
	free(*top);
	*top = NULL;
	return ;
}

void	free_strv(char **strv)
{
	int	i;

	if (!strv)
		return ;
	i = 0;
	while (strv[i])
	{
		free(strv[i]);
		i++;
	}
	free(strv);
	return ;
}

void	free_all(t_arg **a, t_arg **b)
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
