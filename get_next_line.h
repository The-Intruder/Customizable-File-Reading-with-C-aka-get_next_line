/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:59:44 by mnaimi            #+#    #+#             */
/*   Updated: 2021/11/26 17:47:00 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*  Testing Phase Includes  */
/* ------- WARNING -------- */
/* These should be removed  */
/*    before final build    */
# include<stdio.h>
# include <string.h>
/* ------------------------ */

/* Mandatory includes */
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

/* Macros, Typedefs, ..., etc */
typedef struct s_list {
	int				node_fd;
	char			*the_rest;
	struct s_list	*next;
}	t_list;

/* Prototypes */
char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup(const char *src);
t_list	*ft_lstnew(int fd, void *the_rest);
void	ft_lstadd_back(t_list **lst, t_list *new_node);

#endif
