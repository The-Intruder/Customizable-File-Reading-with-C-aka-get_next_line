/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 21:35:34 by mnaimi            #+#    #+#             */
/*   Updated: 2021/11/26 20:40:33 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

/* -------------------------------------------------------------------------- */

char	*get_next_line(int fd)
{
	char		*buf;
	int			count;
	char		*temp;
	char		*dummy_ptr;
	static char	*fd_arr[1024];

	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		if (fd_arr[fd])
			free(fd_arr[fd]);
		return (0);
	}
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	ft_bzero(buf, BUFFER_SIZE + 1);
	temp = (char *)malloc(sizeof(char));
	if (!temp)
		return (NULL);
	ft_bzero(temp, sizeof(char));
	if (fd_arr[fd])
	{
		dummy_ptr = temp;
		temp = ft_strjoin(fd_arr[fd], temp);
		free(fd_arr[fd]);
		fd_arr[fd] = 0;
		free(dummy_ptr);
	}
	while (!ft_strchr(temp, '\n'))
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count <= 0)
		{
			free(buf);
			if (!*temp)
			{
				free(temp);
				return (NULL);
			}
			return (temp);
		}
		dummy_ptr = temp;
		temp = ft_strjoin(temp, buf);
		free(dummy_ptr);
		ft_bzero(buf, BUFFER_SIZE + 1);
	}
	if (ft_strchr(temp, '\n') && (ft_strchr(temp, '\n') + 1))
	{
		dummy_ptr = temp;
		fd_arr[fd] = ft_strdup(ft_strchr(temp, '\n') + 1);
		ft_bzero(ft_strchr(temp, '\n') + 1, \
			ft_strlen(ft_strchr(temp, '\n') + 1));
		temp = ft_strdup(temp);
		free(dummy_ptr);
	}
	free(buf);
	return (temp);
}

/* -------------------------------------------------------------------------- */
