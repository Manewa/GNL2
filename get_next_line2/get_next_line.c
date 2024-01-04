/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:04:22 by namalier          #+#    #+#             */
/*   Updated: 2024/01/04 19:34:14 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_gnllen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_gnljoin(char *s1, char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	join = malloc((ft_gnllen(s1) + len + 1) * sizeof (char));
	if (!join)
		return (NULL);
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (j < len)
		join[i++] = s2[j++];
	join[i] = '\0';
	free (s1);
	return (join);
}

char *ft_gnlchr(char *str, int to_find)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if(str[i] == (char)to_find)
			return((char *)&str[i]);
		i++;
	}
	return (NULL);
}

char *ft_gnldup(char *str)
{
	size_t	i;
	char	*dup;

	i = 0;
	dup = malloc(ft_gnllen(str) + 1 * sizeof (char));
	if (!dup)
		return (NULL);
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char *get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1] = "";
	char		*line;
	size_t		nread;
	char		*newline;
	int			stop;

	line = ft_gnldup(buf);
	while (!(ft_gnlchr(line, '\n')) && (nread = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[nread] = '\0';
		line = ft_gnljoin(line, buf, nread);
	}
	if (ft_gnllen(line) == 0)
		return (NULL);
	newline = ft_gnlchr(line, '\n');
	if (newline != NULL)
	{
		stop = ft_checkline(line);
		ft_gnlmove(buf, line, stop);
	}
	else
		ft_gnlmove(buf, line, ft_gnllen(line));
	return (line);
}

#include<stdio.h>
#include <fcntl.h>

int main ()
{
	int	fd;
	char	*str = "";

	fd = open("test.txt", O_RDONLY);
	while(str)
	{
		str = get_next_line(fd);
		printf("|%s|", str);
	}
	return (0);
}
