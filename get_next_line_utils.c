/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:20:48 by cravegli          #+#    #+#             */
/*   Updated: 2023/10/09 14:08:47 by cravegli         ###   ########.fr       */
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

char	*fitstr(char *str)
{
	char	*new;
	int		i;

	new = (char *)malloc(sizeof(char) * ft_strlen(str));
	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	free(str);
	new[i] = 0;
	return (new);
}
