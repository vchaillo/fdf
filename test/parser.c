/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 14:46:19 by valentin          #+#    #+#             */
/*   Updated: 2014/12/13 16:06:13 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int	create_map(t_env *e)
{
	int	fd;
	int	nb_lines;
	char 	*line;
	char	*tmp;

	nb_lines = 0;
	if (!(fd = open(e->path, O_RDONLY)))
		exit(0);
	printf("avant gnl: %s", line);
	while (get_next_line(fd, &line) == 1)
	{
//		ft_putstr("line");
//		ft_putnbr(nb_lines);
//		ft_putstr(" = ");
		ft_putendl(line);
		nb_lines++;
	}
	return (0);
}
