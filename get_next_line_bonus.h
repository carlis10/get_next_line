/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:08:54 by cravegli          #+#    #+#             */
/*   Updated: 2023/10/31 13:49:20 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <limits.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif
# if BUFFER_SIZE < 1 || BUFFER_SIZE > 100000
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif
# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>

char	*get_next_line(int fd);
char	*fitstr(char *str);
char	*ft_strrchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
int		ft_strlen(char *str);

#endif