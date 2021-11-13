/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:04:15 by gmckinle          #+#    #+#             */
/*   Updated: 2021/11/13 15:07:34 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_working_with_remainder(char **line, char **remainder, ssize_t bytes)
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
	if (bytes == 0 && !p)
	{
		*line = ft_strdup(*remainder);
		free(*remainder);
		*remainder = NULL;
		return (0);
	}
	return (150);
}

static void	ft_if_remainder(char **remainder, char **buf)
{
	char	*to_free;

	if (!*remainder)
		*remainder = ft_strdup(*buf);
	else
	{
		to_free = *remainder;
		*remainder = ft_join(*remainder, *buf);
		free(to_free);
	}
}

int	get_next_line(int fd, char **line)
{
	ssize_t			bytes;
	char			*buf;
	int				ret_val;
	static char		*remainder;

	if (fd < 0 || BUFFER_SIZE < 1 || line == NULL)
		return (-1);
	while (1)
	{
		buf = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
		if (!buf)
			return (-1);
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buf);
			return (-1);
		}
		ft_if_remainder(&remainder, &buf);
		ret_val = ft_working_with_remainder(line, &remainder, bytes);
		free(buf);
		if (ret_val != 150)
			return (ret_val);
	}
	return (0);
}