/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 21:35:34 by mnaimi            #+#    #+#             */
/*   Updated: 2021/11/27 18:19:22 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	ptr = (char *) malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	return ((void *) ptr);
}

char	*final_step(char **fd_arr, int fd, char **line_ptr)
{
	void	*dummy_ptr;

	if (!*line_ptr)
		return (NULL);
	if (ft_strchr(*line_ptr, '\n') && (ft_strchr(*line_ptr, '\n') + 1))
	{
		dummy_ptr = *line_ptr;
		fd_arr[fd] = ft_strdup(ft_strchr(*line_ptr, '\n') + 1);
		ft_bzero(ft_strchr(*line_ptr, '\n') + 1, \
			ft_strlen(ft_strchr(*line_ptr, '\n') + 1));
		*line_ptr = ft_strdup(*line_ptr);
		free(dummy_ptr);
	}
	return (*line_ptr);
}

char	*read_file(char **line_ptr, int fd)
{
	void	*dummy_ptr;
	char	*buf;
	int		count;

	buf = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buf)
		return (NULL);
	while (!ft_strchr(*line_ptr, '\n'))
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count <= 0)
		{
			if (!**line_ptr)
				return (free(buf), free(*line_ptr), NULL);
			return (free(buf), *line_ptr);
		}
		dummy_ptr = *line_ptr;
		*line_ptr = ft_strjoin(*line_ptr, buf);
		free(dummy_ptr);
		ft_bzero(buf, BUFFER_SIZE + 1);
	}
	return (free(buf), *line_ptr);
}

char	*get_next_line(int fd)
{
	static char	*fd_arr[1024];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		if (fd_arr[fd])
			free(fd_arr[fd]);
		return (NULL);
	}
	line = NULL;
	if (fd_arr[fd])
	{
		line = ft_strdup(fd_arr[fd]);
		free(fd_arr[fd]);
		fd_arr[fd] = 0;
	}
	if (!line)
	{
		line = (char *)ft_calloc(1, sizeof(char));
		if (!line)
			return (NULL);
	}
	line = read_file(&line, fd);
	line = final_step(fd_arr, fd, &line);
	return (line);
}
