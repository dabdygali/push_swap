/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_atoi_compatible.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:44:28 by dabdygal          #+#    #+#             */
/*   Updated: 2023/10/26 12:37:30 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	str_is_less(char *str, long max, int lim)
{
	long	num;

	num = 0;
	while (lim)
	{
		num = (num * 10) + (*str - '0');
		str++;
		lim--;
	}
	if (num > max)
		return (0);
	return (1);
}

static int	is_within_int(int sign, char *str)
{
	long	order;
	long	max;
	int		lim;
	int		i;

	max = INT_MAX;
	if (sign < 0)
		max = (long) -1 * INT_MIN;
	order = 1;
	lim = 0;
	while (max / order)
	{
		order *= 10;
		lim++;
	}
	order /= 10;
	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	if (i > lim)
		return (0);
	if (i == lim)
		return (str_is_less(str, max, lim));
	return (1);
}

/**
 * @brief Checks if string number is a valid  parameter for ft_atoi().
 * @details A function checks whether a string number is readable by ft_atoi()
 * and fits within int limits.
 * @param str A pointer to a string representing a number.
 * @return Returns 1 if string is an int, otherwise returns 0.
*/
int	ft_is_atoi_compatible(char *str)
{
	int	sign;

	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!ft_isdigit(*str))
		return (0);
	while (*str == '0')
		str++;
	if (ft_isdigit(*str) && !is_within_int(sign, str))
		return (0);
	return (1);
}
