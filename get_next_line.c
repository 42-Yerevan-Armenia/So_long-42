/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakhurs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 14:23:17 by arakhurs          #+#    #+#             */
/*   Updated: 2022/07/30 14:23:29 by arakhurs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_zero_bytes(char **backup)
{
	char	*line;

	line = ft_strdup(*backup);
	free(*backup);
	*backup = NULL;
	return (line);
}

static char	*ft_check_backup(char **backup)
{
	char	*newline;
	char	*temp;
	size_t	n;

	if (!(*backup))
		return (NULL);
	newline = NULL;
	if (ft_strchr(*backup, '\n'))
	{
		n = ft_strchr(*backup, '\n') - *backup + 1;
		newline = ft_substr(*backup, 0, n);
		temp = ft_strdup((*backup) + n);
		if (*temp == '\0')
		{
			free(temp);
			temp = NULL;
		}
		free(*backup);
		*backup = temp;
	}
	return (newline);
}

char	*get_next_line(int fd)
{
	char			temp_line[BUFFER_SIZE + 1];
	ssize_t			read_bytes;
	static char		*backup;
	char			*line;

	if (fd < 0 || fd > 65536 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_check_backup(&backup);
	if (line != NULL)
		return (line);
	read_bytes = 1;
	while (read_bytes != 0)
	{
		read_bytes = read(fd, temp_line, BUFFER_SIZE);
		if (read_bytes == -1)
			return (NULL);
		temp_line[read_bytes] = '\0';
		if (read_bytes > 0)
			backup = ft_strjoin(backup, temp_line);
		line = ft_check_backup(&backup);
		if (line != NULL)
			return (line);
	}
	line = ft_zero_bytes(&backup);
	return (line);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	str = (char *)malloc(sizeof(*s) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
