/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 19:19:07 by vchaillo          #+#    #+#             */
/*   Updated: 2015/01/06 19:55:34 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		**create_map(t_env *e)
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
		grid[i] = create_t_point_tab(line);
		i++;
	}
	close(fd);
	return (grid);
}

t_point		*create_t_point_tab(char *line)
{
	t_point		*tab;
	char		**tmp;
	int			tab_len;
	int			i;

	i = 0;
	tmp = ft_strsplit(line, ' ');
	if (!(tab = (t_point *)malloc(sizeof(t_point) * get_tab_len(tmp))))
		malloc_error();
	//to be continue
}

int			get_grid_len(t_env *e)
{
	char		*buffer;
	int			fd;
	int			len;
	int			ret;

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

int			get_tab_len(char **tab)
{
	int			len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
}
