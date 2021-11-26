/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 21:35:34 by mnaimi            #+#    #+#             */
/*   Updated: 2021/11/26 17:47:04 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

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

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*myptr;

	i = 0;
	myptr = (char *)s;
	while (i++ < n)
		*(myptr++) = 0;
}

/* -------------------------------------------------------------------------- */
/*

   //free the static variable in case allocation fails in buf or temp,
   //but bear in mind that static will be wiped and future function calling
   //(in case of memory being freed for te allocation to succedd) 
   //will result in errors

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
*/
/* -------------------------------------------------------------------------- */

t_list	*get_node(int fd, t_list **tracer)
{
	while ((*tracer) -> next)
	{
		if ((*tracer) -> node_fd == fd)
			return (*tracer);
		tracer = &(*tracer) -> next;
	}
	return (NULL);
}

/* -------------------------------------------------------------------------- */

char	*get_next_line(int fd)
{
	static t_list	fd_list;
	char			*buf;
	char			*line;
	t_list			*ptr_to_node;

	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		if (fd_list)
			ft_lstclear(fd_list);
		return (NULL);
	}
	selected_node = get_node(fd, &fd_list);
	if (!selected_node)
		ptr_to_node = ft_lstnew()
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	ft_bzero(buf, BUFFER_SIZE + 1);
	line = (char *)malloc(sizeof(char));
	if (!line)
		return (NULL);
	ft_bzero(line, sizeof(char));
	

}

