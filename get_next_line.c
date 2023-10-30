/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:19:40 by cravegli          #+#    #+#             */
/*   Updated: 2023/10/30 16:39:21 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *buff)
{
	int		len;
	char	*line;
	int		ex_len;

	len = 0;
	ex_len = 1;
	if (!buff[len])
		return (NULL);
	while (buff[len] != '\n' && buff[len])
		len++;
	if (buff[len] == '\n')
		ex_len++;
	line = (char *)ft_calloc(len + ex_len, sizeof(char));
	if (!line)
		return (NULL);
	len = 0;
	while (buff[len] != '\n' && buff[len])
	{
		line[len] = buff[len];
		len++;
	}
	if (buff[len] == '\n')
		line[len] = '\n';
	return (line);
}

char	*get_res(char *buff)
{
	char	*res;
	int		len;
	int		i;

	len = 0;
	while (buff[len] && buff[len] != '\n')
		len++;
	if (!buff[len])
	{
		free(buff);
		return (NULL);
	}
	res = (char *)ft_calloc((ft_strlen(buff) - len) + 1, sizeof(char));
	if (!res)
	{
		free(buff);
		return (NULL);
	}
	i = 0;
	len++;
	while (buff[len])
		res[i++] = buff[len++];
	free(buff);
	return (res);
}

char	*ft_start_read(char *res, int fd, char *buff)
{
	int		b_read;
	char	*temp;

	b_read = 1;
	while (b_read && !(ft_strrchr(res, '\n')))
	{
		b_read = read(fd, buff, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(buff);
			free(res);
			return (NULL);
		}
		buff[b_read] = 0;
		temp = ft_strjoin(res, buff);
		free(res);
		res = temp;
	}
	free(buff);
	return (res);
}

char	*ft_read(char *res, int fd)
{
	char	*buff;

	if (!res)
		res = ft_calloc(1, 1);
	if (!res)
		return (NULL);
	buff = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
	{
		free(res);
		return (NULL);
	}
	return (ft_start_read(res, fd, buff));
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = ft_read(buffer, fd);
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	if (!line)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = get_res(buffer);
	return (line);
}
