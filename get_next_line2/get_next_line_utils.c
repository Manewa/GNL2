/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:25:13 by namalier          #+#    #+#             */
/*   Updated: 2024/01/04 19:34:17 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_checkline(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}

void ft_gnlmove(char *buf, char *line, size_t stop)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!buf && !line && !stop)
		return ;
	while (line[i] && line[i] != '\n')
		i++;
	if (i == stop && line[i + 1])
	{
		while (line[++i])
			buf[j++] = line[i];
		line[++stop] = '\0';
	}
	buf[j] = '\0';
}
