/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:23:45 by dabdygal          #+#    #+#             */
/*   Updated: 2023/10/25 15:30:00 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

/**
 * @brief Converts argument vector to unique integers stack.
 *
 * Function checks strings for are integers within int range, no duplicates and
 * converts them into integer vector. If check failed displays ERR_MSG warning.
 * @param argc Arguments count.
 * @param argv Arguments vector.
 * @return If non-integer or duplicate is found among arguments returns NULL,
 * otherwise returns int pointer to a int vector.
*/
int	*parse_args(int argc, char *argv[])
{
	int	i;
	int	*res;

	if (argc < 2)
	{
		ft_putstr_fd(ERR_MSG, STDERR_FILENO);
		return (NULL);
	}
	res = (int *) malloc((argc - 1) * sizeof(int));
	i = 0;
	while (i < argc - 1)
	{
		if (ft_is_atoi_compatible(argv[i + 1]) == 0)
		{
			ft_putstr_fd(ERR_MSG, STDERR_FILENO);
			free(res);
			return (NULL);
		}
		res[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (res);
}
