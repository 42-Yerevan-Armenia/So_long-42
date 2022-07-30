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

static int	ft_nbofwords(char *s, char c)
{
	int	count;
	int	is_word;

	count = 0;
	is_word = 0;
	while (*s)
	{
		if (is_word == 0 && *s != c)
		{
			is_word = 1;
			count++;
		}
		else if (is_word == 1 && *s == c)
			is_word = 0;
		s++;
	}
	return (count);
}

static int	ft_strlenword(char *s, char c)
{
	int	len;

	len = 0;
	while (*s != c && *s)
	{
		len++;
		s++;
	}
	return (len);
}

static void	*my_free(char **tab, int i)
{
	while (i-- > 0)
	{
		free(tab[i]);
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		nb_ofwords;
	int		i;
	char	**tab;

	i = 0;
	nb_ofwords = ft_nbofwords((char *)s, c);
	tab = (char **)malloc(nb_ofwords * sizeof(char *) + 1);
	if (!tab)
		return (NULL);
	while (nb_ofwords--)
	{
		while (*s == c && *s)
			s++;
		tab[i] = ft_substr((char *)s, 0, ft_strlenword((char *)s, c));
		if (!tab[i])
			return (my_free(tab, i));
		s = s + ft_strlenword((char *)s, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
