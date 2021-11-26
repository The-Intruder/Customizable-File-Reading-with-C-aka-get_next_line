/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:59:35 by mnaimi            #+#    #+#             */
/*   Updated: 2021/11/26 18:08:45 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

/* -------------------------------------------------------------------------- */
/*
char	*get_next_line(int fd)
{
	char		*buf;
	int			count;
	char		*temp;
	static char	*the_rest;
	void		*dummy_ptr;
	
	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		if (the_rest)
			free(the_rest);
		return (0);
	}
	buf = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
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
		the_rest = 0;
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
	if (ft_strchr(temp, '\n') && ft_strchr(temp, '\n') + 1)
	{
		the_rest = strdup(ft_strchr(temp, '\n') + 1);
		dummy_ptr = temp;
		temp = ft_substr(temp, 0, (ft_strchr(temp, '\n') - temp) + 1);
		free(dummy_ptr);
	}
	free(buf);
	return (temp);
}
*/
/* -------------------------------------------------------------------------- */

char	*get_next_line(int fd)
{
	char		*buf;
	int			count;
	char		*temp;
	static char	*the_rest;
	char		*dummy_ptr;

	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		if (the_rest)
			free(the_rest);
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
	if (the_rest)
	{
		dummy_ptr = temp;
		temp = ft_strjoin(the_rest, temp);
		free(the_rest);
		the_rest = 0;
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
		the_rest = ft_strdup(ft_strchr(temp, '\n') + 1);
		ft_bzero(ft_strchr(temp, '\n') + 1, \
			ft_strlen(ft_strchr(temp, '\n') + 1));
		temp = ft_strdup(temp);
		free(dummy_ptr);
	}
	free(buf);
	return (temp);
}

/* -------------------------------------------------------------------------- */
