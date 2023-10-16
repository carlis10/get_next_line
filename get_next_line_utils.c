/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Carlos <Carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:20:48 by cravegli          #+#    #+#             */
/*   Updated: 2023/10/16 11:45:57 by Carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*l;
	size_t			i;

	i = 0;
	l = s;
	while (i < n)
	{
		l[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*m;

	m = (void *)malloc(count * size);
	if (!m)
		return (NULL);
	ft_bzero(m, count * size);
	return (m);
}

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	p;
	int				size;

	p = (unsigned char)c;
	size = ft_strlen((char *)s);
	while (size >= 0)
	{
		if (s[size] == p)
			return ((char *)(s + size));
		size--;
	}
	return (NULL);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	d_len;
	size_t	s_len;

	d_len = ft_strlen(dst);
	s_len = ft_strlen((char *)src);
	j = d_len;
	i = 0;
	if (dstsize <= d_len)
		return (s_len + dstsize);
	while (src[i] && (d_len + i) < (dstsize - 1))
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = 0;
	if (dstsize < d_len)
		d_len = dstsize;
	return (d_len + s_len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_size;
	size_t	i;

	i = 0;
	src_size = 0;
	while (src[src_size])
		src_size++;
	if (dstsize > 0)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_size);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	size;

	size = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	s3 = (char *)ft_calloc(size, sizeof(char));
	if (!s3)
		return (0);
	ft_strlcpy(s3, s1, size);
	ft_strlcat(s3, s2, size);
	return (s3);
}
