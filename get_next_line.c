/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:19:40 by cravegli          #+#    #+#             */
/*   Updated: 2023/10/09 14:03:42 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;
	int		i;
	char	chr[1];

	line = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!line)
		return (NULL);
	i = 0;
	read(fd, chr, 1);
	if (chr[0] != '\n' && chr[0])
		line[i] = chr[0];
	else
	{
		free(line);
		return (NULL);
	}
	while (chr[0] != '\n' && chr[0])
	{
		read(fd, chr, 1);
		i++;
		line[i] = chr[0];
	}
	line[i] = 0;
	return (fitstr(line));
}
