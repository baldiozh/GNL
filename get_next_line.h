#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include	<unistd.h>
# include 	<stdlib.h>
# include	<fcntl.h>

# ifndef	BUFFER_SIZE
#  define	BUFFER_SIZE	4026
# endif

int		get_next_line(int fd, char **line);
char	*ft_strdup(char *src);
size_t	ft_strlen(const char *str);
char	*ft_join(char const *s1, char const *s2);
char	*ft_strchr(char *str, int ch);

#endif
