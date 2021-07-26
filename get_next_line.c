#include "get_next_line.h"

static int	ft_work_with_remainder(char **line, char **remainder, ssize_t bytes)
{
	char	*p;
	char	*to_free;

	p = ft_strchr(*remainder, '\n');
	if (p != NULL)
	{
		*p = '\0';
		*line = ft_strdup(*remainder);
		to_free = *remainder;
		*remainder = ft_strdup(++p);
		free(to_free);
		return (1);
	}
	if ((bytes == 0) && (p == NULL))
	{
		*line = ft_strdup(*remainder);
		free(*remainder);
		*remainder = NULL;
		return (0);
	}
	return (150);
}

static void	ft_rewrite_remainder(char **remainder, char *buf) 
	char	*to_free; 			

	if (!*remainder)
		*remainder = ft_strdup(buf);			
	else
	{
		to_free = *remainder;
		*remainder = ft_join(*remainder, buf);
		free(to_free);
	}
}

int	get_next_line(int fd, char **line)
{
	ssize_t			bytes;
	char			buf[BUFFER_SIZE + 1]; 
	int				ret_ft;
	static char		*remainder;

	if (read(fd, NULL, 0) == -1 || BUFFER_SIZE < 1 || line == NULL) 
		return (-1);
	while (1)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		buf[bytes] = '\0';
		if (bytes == -1)
		{
			free(buf);
			return (-1);
		}
		ft_rewrite_remainder(&remainder, buf);
		ret_ft = ft_work_with_remainder(line, &remainder, bytes);
		if (ret_ft == 1 || ret_ft == 0)
			return (ret_ft);
	}
	return (0);
}
