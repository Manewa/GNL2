/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:04:22 by namalier          #+#    #+#             */
/*   Updated: 2024/01/05 17:56:14 by namalier         ###   ########.fr       */
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

char *ft_gnljoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*join;

	if (!s2)
		return (NULL);
	i = 0;
	j = 0;
	join = malloc((ft_gnllen(s1) + ft_gnllen(s2) + 1) * sizeof (char));
	if (!join)
		return (NULL);
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j])
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
	if (str[i])
		dup = malloc(ft_gnllen(str) + 1 * sizeof (char));
	else
		dup = malloc(1 * sizeof(char));
	if (!dup)
		return (NULL);
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

char *get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1] = "\0";
	char		*line;
	ssize_t		nread;

	nread = 1;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = ft_gnldup(buf);
	if (!(ft_gnlchr(line, '\n')))
		nread = read(fd, buf, BUFFER_SIZE);
	while (!(ft_gnlchr(line, '\n')) && nread > 0)
	{
		buf[nread] = '\0';
		line = ft_gnljoin(line, buf);
		if (!(ft_gnlchr(line, '\n')))
			nread = read(fd, buf, BUFFER_SIZE);
	}
	if (ft_gnllen(line) == 0 || nread < 0)
		return (free (line), NULL);
	line = ft_movenewline(line, buf);
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
		printf("%s", str);
		free (str);
		str = get_next_line(fd);
		printf("%s", str);
		free (str);
		str = get_next_line(fd);
		printf("%s", str);
		free (str);
		str = get_next_line(fd);
		printf("%s", str);
		free (str);
		str = get_next_line(fd);
		printf("%s", str);
		free (str);
	}
	close(fd);
	return (0);
}
