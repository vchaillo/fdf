/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 19:34:55 by vchaillo          #+#    #+#             */
/*   Updated: 2014/12/15 19:42:17 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_map(t_env *e)
{
	int		fd;
	int		tab_len;
	char	*line;
	char	**grid;

	if (!(fd = open(e->path, O_RDONLY)))
		exit(0);
	if (!(grid = (char **)malloc(sizeof(char *) * tab_len)))
		exit(0);
	while (get_next_line(fd, &line) == 1)
	{
		
	}
}
