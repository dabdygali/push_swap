/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkwarn_argc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:53:56 by dabdygal          #+#    #+#             */
/*   Updated: 2023/10/23 10:55:17 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <unistd.h>
#include "libft.h"

/**
 * @brief Checks and warns the arguments count.
 *
 * Function checks whether arguments count is within the range between min
 * and max. If not within the range makes warning on standard error output.
 * @param argc Arguments counter.
 * @param min_argc Lower limit of the range of possible arguments count.
 * @param max_argc Upper limit of the range of possible arguments count.
 * @return Returns -1 if arguments count is not within the range or range
 * limits are not valid. Otherwise returns 0.
*/
int	ft_checkwarn_argc(int argc, int min_argc, int max_argc)
{
	if (min_argc > max_argc || min_argc < 0 || max_argc < 0)
	{
		errno = ENOSYS;
		ft_putstr_fd("'min_argc','max_argc' are setup wrong\n", STDERR_FILENO);
		return (-1);
	}
	if (argc < min_argc)
	{
		errno = EINVAL;
		ft_putstr_fd("Not enough arguments\n", STDERR_FILENO);
		return (-1);
	}
	if (argc > max_argc)
	{
		errno = EINVAL;
		ft_putstr_fd("Too much arguments\n", STDERR_FILENO);
		return (-1);
	}
	return (0);
}
