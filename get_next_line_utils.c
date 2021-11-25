/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:59:57 by mnaimi            #+#    #+#             */
/*   Updated: 2021/11/25 15:19:38 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

/* -------------------------------------------------------------------------- */

static char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_strdup(const char *src)
{
	int		src_len;
	char	*dest;

	src_len = ft_strlen(src);
	dest = (char *)ft_calloc(src_len + 1, sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_strcpy(dest, src);
	return (dest);
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
