/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:59:35 by mnaimi            #+#    #+#             */
/*   Updated: 2021/11/25 16:07:28 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

/* -------------------------------------------------------------------------- */

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/* -------------------------------------------------------------------------- */

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = (char *) malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < count * size)
		ptr[i++] = 0;
	return ((void *) ptr);
}

/* -------------------------------------------------------------------------- */

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	my_c;

	i = 0;
	my_c = (char) c;
	while (s[i])
	{
		if (s[i] == my_c)
			return ((char *)&s[i]);
		i++;
	}
	if (my_c == 0 && s[i] == my_c)
		return ((char *)&s[i]);
	return (0);
}

/* -------------------------------------------------------------------------- */
char	*get_next_line(int fd)
{
	char		*buf;
	int			count;
	char		*temp;
	static char	*the_rest;
	void		*dummy_ptr;

	if (BUFFER_SIZE <= 0)
	{
		if (the_rest)
			free(the_rest);
		return (NULL);
	}
/* buf allocation included in while loop instead of in the beginning*/

	//buf = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	//if (!buf)
	//	return (NULL);
	temp = (char *)ft_calloc(1, sizeof(char));
	if (!temp)
		return (NULL);
	if (the_rest && *the_rest)
	{
		dummy_ptr = temp;
		temp = ft_strjoin(the_rest, temp);
		free(the_rest);
		the_rest = 0;
		free(dummy_ptr);
	}
	while (!ft_strchr(temp, '\n'))
	{
		buf = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buf)
			return (NULL);
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
		//if (buf && *buf)
		//	free(buf);
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
