/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakhurs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 13:51:47 by arakhurs          #+#    #+#             */
/*   Updated: 2022/07/30 13:51:52 by arakhurs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		i++;
		while (*s && *s == c)
			s++;
		if (*s == '\0')
			i--;
		while (*s && *s != c)
			s++;
	}
	return (i);
}

static char	**fill_string(char **store, char const *s, char c)
{
	size_t	len;
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c)
			{
				len++;
				s++;
			}
			store[i++] = ft_substr(s - len, 0, len);
		}
		else
			s++;
	}
	store[i] = 0;
	return (store);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	count;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	split = malloc(sizeof(char *) * (count + 1));
	if (!split)
		return (NULL);
	split = fill_string(split, s, c);
	return (split);
}
