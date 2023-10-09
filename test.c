/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:35:05 by cravegli          #+#    #+#             */
/*   Updated: 2023/10/09 14:16:59 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char const *argv[])
{
	int		r;
	int		r2;
	char	*c;

	if (argc == 2)
	{
		r = open(argv[1], 0);
		c = get_next_line(r);
		while (c)
		{
			printf("%s\n", c);
			c = get_next_line(r);
		}
	}
	if (argc > 2)
	{
		r = open(argv[1], 0);
		r2 = open(argv[2], 0);
		c = get_next_line(r);
		printf("%s\n", c);
		c = get_next_line(r2);
		printf("%s\n", c);
		c = get_next_line(r);
		printf("%s\n", c);
		c = get_next_line(r2);
		printf("%s\n", c);
		c = get_next_line(r);
		printf("%s\n", c);
		c = get_next_line(r2);
		printf("%s\n", c);
	}
	return (0);
}
