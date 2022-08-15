/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakhurs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 14:23:17 by arakhurs          #+#    #+#             */
/*   Updated: 2022/07/30 14:23:30 by arakhurs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*mywhile(int fd, char *sline)
{
	char	buffer[4];
	long	rsize;

	while (1)
	{	
		rsize = read(fd, buffer, 1);
		buffer[rsize] = '\0';
		if (rsize == -1)
			return (0);
		if (!sline)
			sline = ft_strdup(buffer);
		else
			sline = ft_strjoin(sline, buffer);
		if (ft_strchr(buffer, '\n') || rsize == 0)
			break ;
	}
	return (sline);
}

char	*get_next_line(int fd)
{
	static char	*sline;
	char		*until_n;
	char		*tline;
	long		slinelen;

	sline = mywhile(fd, sline);
	if (!sline)
		return (NULL);
	slinelen = ft_strlen(sline) - ft_strlen(ft_strchr(sline, '\n')) + 1;
	until_n = ft_substr(sline, 0, slinelen);
	tline = sline;
	sline = ft_substr(sline, slinelen, ft_strlen(sline));
	free(tline);
	return (until_n);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != c)
	{
		if (s[i] == '\0')
			return (0);
		i++;
	}
	return ((char *)(s + i));
}

char	*ft_strdup(char *s1)
{
	char	*s;
	size_t	i;

	i = 0;
	s = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (!s || !s1)
		return (0);
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
