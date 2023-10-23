/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:44:28 by dabdygal          #+#    #+#             */
/*   Updated: 2023/10/23 13:41:40 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

int	ft_str_is_int(char *str)
{
	int	sign;
	int	a;

	a = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
}
int	ft_atoi(const char *str)
{
	int	to_return;
	int	sign;

	to_return = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else
		if (*str == '+')
			str++;
	while (*str == '0')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		to_return = (to_return * 10) + (*str - '0');
		str++;
	}
	to_return = sign * to_return;
	return (to_return);
}
