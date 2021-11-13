/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:04:20 by gmckinle          #+#    #+#             */
/*   Updated: 2021/11/13 15:04:21 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include	<unistd.h>
# include 	<stdlib.h>
# include	<fcntl.h>
# include	<sys/types.h>

# ifndef	BUFFER_SIZE
#  define	BUFFER_SIZE	30
# endif

int		get_next_line(int fd, char **line);
char	*ft_strdup(char *src);
size_t	ft_strlen(const char *str);
char	*ft_join(char const *s1, char const *s2);
char	*ft_strcopy(char *dest, char *src);
void	*ft_calloc(size_t num, size_t size);
char	*ft_strchr(char *str, int ch);

#endif