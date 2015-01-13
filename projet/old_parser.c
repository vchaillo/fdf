/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 19:34:55 by vchaillo          #+#    #+#             */
/*   Updated: 2015/01/13 20:28:45 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		**create_map(t_env *e)
{
	int			fd;
	int			i;
	int			j;
	int			grid_len;
	char		*line;
	t_point		**grid;

	i = 0;
	line = NULL;
	if ((fd = open(e->path, O_RDONLY)) == -1)
		open_error(e);
	grid_len = get_grid_len(e);
	if (!(grid = (t_point **)malloc(sizeof(t_point *) * grid_len)))
		malloc_error();
	while (get_next_line(fd, &line) == 1)
	{
		grid[i] = get_t_point_tab(line);
		i++;
	}
	i = 0;
	while (grid[i] != NULL)
	{
		j = 0;
		while (grid[j] != NULL)
		{
			ft_putnbr(grid[i][j].z);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	close(fd);
	return (grid);
}

int			get_grid_len(t_env *e)
{
	int			fd;
	int			len;
	int			ret;
	char		*buffer;

	len = 0;
	buffer = ft_strnew(BUFF_SIZE);
	if ((fd = open(e->path, O_RDONLY)) == -1)
		open_error(e);
	while ((ret = read(fd, buffer, BUFF_SIZE)))
		len += ret;
	close(fd);
	free(buffer);
	return (len);
}

t_point		*get_t_point_tab(char *line)
{
	t_point		*tab;
	char		**tmp;
	int			tab_len;
	int			i;

	i = 0;
	tmp = ft_strsplit(line, ' ');
	tab_len = get_tab_len(tmp);
	if (!(tab = (t_point *)malloc(sizeof(t_point) * tab_len)))
		malloc_error();
	while (tmp[i] != NULL)
	{
		tab[i] = get_point_infos(tmp[i], i);
		i++;
	}
	return (tab);
}

t_point		get_point_infos(char *str, int x)
{
	t_point		point;

	point.x = x;
	point.z = ft_atoi(str);
	return (point);
}

int			get_tab_len(char **tab)
{
	int			len;

	len = 0;
	while (tab[len] != '\0')
		len++;
	return (len);
}
