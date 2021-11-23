/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:59:35 by mnaimi            #+#    #+#             */
/*   Updated: 2021/11/23 22:57:34 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buf;
	int			count;
	//static char	*line;
	char		*temp;

	buf = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	buf[BUFFER_SIZE] = 0;
	count = read(fd, buf, BUFFER_SIZE);
	if (count <= 0)
		return (0);
	temp = (char *)ft_calloc(1, sizeof(char));
	while (!ft_strchr(temp, '\n'))
		temp = ft_strjoin(temp, buf);
	return (temp);
}
