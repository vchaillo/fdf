/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 19:19:07 by vchaillo          #+#    #+#             */
/*   Updated: 2015/02/15 21:09:37 by vchaillo         ###   ########.fr       */
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
	e->max_z = 0;
	e->max_w = 0;
	if ((fd = open(e->path, O_RDONLY)) == -1)
		open_error(e);
	if (!(grid = (t_point **)malloc(sizeof(t_point *) * get_grid_len(e) + 1)))
		malloc_error();
	while (get_next_line(fd, &line) == 1)
	{
		grid[i] = create_t_point_tab(e, line, i);
		i++;
	}
	e->max_h = i;
	grid[i++] = NULL;
	close(fd);
	return (grid);
}

t_point			*create_t_point_tab(t_env *e, char *line, int y)
{
	t_point		*tab;
	char		**tmp;
	int			i;

	i = 0;
	tmp = ft_strsplit(line, ' ');
	if (!(tab = (t_point *)malloc(sizeof(t_point) * get_tab_len(tmp) + 1)))
		malloc_error();
	while (tmp[i] != '\0')
	{
		if (*tmp[i] != '\n')
			tab[i] = get_point_infos(e, tmp[i], i, y);
		i++;
	}
	if (i > e->max_w)
		e->max_w = i;
	tab[i++].x = '\0';
	tab[i++].y = '\0';
	tab[i++].z = '\0';
	return (tab);
}

t_point			get_point_infos(t_env *e, char *str, int x, int y)
{
	t_point		point;

	point.x = x;
	point.y = y;
	point.z = ft_atoi(str);
	if (point.z > e->max_z)
		e->max_z = point.z;
	return (point);
}
