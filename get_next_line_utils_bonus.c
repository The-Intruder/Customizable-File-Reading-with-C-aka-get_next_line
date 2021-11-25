/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 21:35:47 by mnaimi            #+#    #+#             */
/*   Updated: 2021/11/25 21:47:53 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

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

char	*ft_strdup(const char *src)
{
	int		src_len;
	char	*dest;
	size_t	i;

	src_len = ft_strlen(src);
	dest = (char *)ft_calloc(src_len + 1, sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

/* -------------------------------------------------------------------------- */

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s_out;
	size_t	the_len;
	size_t	i;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
	{
		s_out = (char *) ft_calloc(1, sizeof(char));
		if (s_out == NULL)
			return (0);
		return (s_out);
	}
	the_len = 0;
	i = 0;
	while (s[start++] && i++ < len)
		++the_len;
	s_out = (char *) ft_calloc(the_len + 1, sizeof(char));
	if (s_out == NULL)
		return (0);
	i = 0;
	start -= (the_len + 1);
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
	output_str = (char *) ft_calloc(i + 1, sizeof(char));
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
	return (output_str);
}

/* -------------------------------------------------------------------------- */
