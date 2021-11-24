/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:59:35 by mnaimi            #+#    #+#             */
/*   Updated: 2021/11/24 21:57:39 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buf;
	int			count;
	char		*temp;
	static char	*the_rest;
	void		*dummy_ptr;
	
	buf = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	temp = (char *)ft_calloc(1, sizeof(char));
	if (!temp)
		return (NULL);
	if (the_rest)
	{
		dummy_ptr = temp;
		temp = ft_strjoin(the_rest, temp);
		free(the_rest);
		the_rest = NULL;
		free(dummy_ptr);
	}
	count = 1;
	while (ft_strchr(temp, '\n') == 0)
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count <= 0)
		{
			free(buf);
			free(temp);
			free(the_rest);
			return (NULL);
		}
		dummy_ptr = temp;
		temp = ft_strjoin(temp, buf);
		free(dummy_ptr);
	}
	if (ft_strchr(temp, '\n'))
	{
		the_rest = strdup(ft_strchr(temp, '\n') + 1);
		dummy_ptr = temp;
		temp = ft_substr(temp, 0, (ft_strchr(temp, '\n') - temp) + 1);
		free(dummy_ptr);
	}
	else
		the_rest = 0;
	free(buf);
	return (temp);
}
