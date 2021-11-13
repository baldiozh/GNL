/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:01:06 by gmckinle          #+#    #+#             */
/*   Updated: 2021/11/13 15:08:49 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main()
{
	char	*line;
	int		fd;
	int 	i;
	fd = open ("test", O_RDONLY);
	while ((i = get_next_line(fd, &line)))
	{
		printf("%d - %s\n", i, line);
		free(line);
	}
	printf("%d - %s\n", i, line);
	free(line);
	return (0);
}
