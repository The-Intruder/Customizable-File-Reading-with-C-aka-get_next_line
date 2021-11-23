/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:59:57 by mnaimi            #+#    #+#             */
/*   Updated: 2021/11/23 22:57:45 by mnaimi           ###   ########.fr       */
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

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	ptr = (char *) malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
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

static size_t	check_len(const char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			s_out_len;

	i = 0;
	s_out_len = 0;
	while (s[start++] && i++ < len)
		++s_out_len;
	return (s_out_len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*s_out;
	size_t	i;
	size_t	the_len;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (s_len < start)
	{
		s_out = (char *) ft_calloc(1, sizeof(char));
		if (s_out == NULL)
			return (0);
		return (s_out);
	}
	the_len = check_len(s, start, len);
	s_out = (char *) ft_calloc(the_len + 1, sizeof(char));
	if (s_out == NULL)
		return (0);
	i = 0;
	while (s[start] && i < len)
		s_out[i++] = s[start++];
	return (s_out);
}

/* -------------------------------------------------------------------------- */

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*output_str;
	size_t	output_i;

	if (!s1 || !s2)
		return (0);
	i = ft_strlen(s1) + ft_strlen(s2);
	output_str = (char *) ft_calloc(sizeof(char), i + 1);
	if (!output_str)
		return (0);
	else if (!i)
		return (output_str);
	i = 0;
	output_i = 0;
	while (s1[i])
		output_str[output_i++] = s1[i++];
	i = 0;
	while (s2[i])
		output_str[output_i++] = s2[i++];
	//output_str[output_i] = '\0';
	return (output_str);
}

/* -------------------------------------------------------------------------- */
