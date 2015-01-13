/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 19:19:07 by vchaillo          #+#    #+#             */
/*   Updated: 2015/01/13 21:03:06 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point			**create_map(t_env *e)
{
	t_point		**grid;
	char		*line;
	int			fd;
	int			i;

	i = 0;
	line = NULL;
	if ((fd = open(e->path, O_RDONLY)) == -1)
		open_error(e);
	if (!(grid = (t_point **)malloc(sizeof(t_point *) * get_grid_len(e))))
		malloc_error();
	while (get_next_line(fd, &line) == 1)
	{
		grid[i] = create_t_point_tab(line, i);
		i++;
	}
	close(fd);
	return (grid);
}

t_point			*create_t_point_tab(char *line, int y)
{
	t_point		*tab;
	char		**tmp;
	int			i;

	i = 0;
	tmp = ft_strsplit(line, ' ');
	if (!(tab = (t_point *)malloc(sizeof(t_point) * get_tab_len(tmp))))
		malloc_error();
	while (tmp[i])
	{
		tab[i] = get_point_infos(tmp[i], i, y);
		i++;
	}
	return (tab);
}

t_point			get_point_infos(char *str, int x, int y)
{
	t_point		point;

	point.x = x;
	point.y = y;
	point.z = ft_atoi(str);
	return (point);
}
