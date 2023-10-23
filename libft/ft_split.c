/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:58:58 by dabdygal          #+#    #+#             */
/*   Updated: 2023/07/12 18:34:25 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	calc_size(char const *s, char c)
{
	size_t	size;
	size_t	i;

	while (*s == c && *s != 0)
		s++;
	i = 0;
	size = 1;
	if (*s)
		size = 2;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != 0)
			size++;
		i++;
	}
	return (size);
}

static char	*cpy_until_c(char const *s, char c)
{
	size_t	i;
	char	*str;

	while (*s == c && *s)
		s++;
	i = 0;
	while (s[i] != c && s[i])
		i++;
	str = (char *) malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] != c && s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

static char	*next_str(char const *s, char c)
{
	while (*s && ((*s == c && *(s + 1) == c) || *s != c))
	{
		s++;
	}
	if (*s)
		s++;
	return ((char *) s);
}

char	**ft_split(char const *s, char c)
{
	char	**str_arr;
	size_t	size;
	size_t	i;

	if (!s)
		return (NULL);
	size = calc_size(s, c);
	str_arr = (char **) malloc(sizeof(char *) * size);
	if (!str_arr)
		return (NULL);
	i = 0;
	while (*s == c && *s)
		s++;
	while (i < size - 1)
	{
		str_arr[i] = (char *) cpy_until_c(s, c);
		s = next_str(s, c);
		i++;
	}
	str_arr[size - 1] = NULL;
	return (str_arr);
}
