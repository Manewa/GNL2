/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:03:29 by namalier          #+#    #+#             */
/*   Updated: 2024/01/04 19:32:26 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*ft_gnldup(char *src);
char	*ft_gnlchr(char *str, int to_find);
char	*ft_gnljoin(char *s1, char *s2, size_t len);
int		ft_gnllen(char *str);
int		ft_checkline(char *line);
void	ft_gnlmove(char *buf, char *line, size_t stop);
char	*get_next_line(int fd);

#endif
