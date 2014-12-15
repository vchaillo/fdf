/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 19:34:55 by vchaillo          #+#    #+#             */
/*   Updated: 2014/12/15 20:49:18 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			create_map(t_env *e)
{
	int		fd;
	int		i;
	int		tab_len;
	char	*line;
	char	**grid;

	i = 0;
	line = NULL;
	if (!(fd = open(e->path, O_RDONLY)))
		exit(0);
	tab_len = get_tab_len(e);
	if (!(grid = (char **)malloc(sizeof(char *) * tab_len)))
		exit(0);
	while (get_next_line(fd, &line) == 1)
	{
		grid[i] = ft_strdup(line);
		i++;
	}
	i = 0;
	while (grid[i])
	{
		ft_putendl(grid[i]);
		i++;
	}
}

int		get_tab_len(t_env *e)
{
	int		fd;
	int		i;
	int		ret;
	char	*buffer;

	i = 0;
	buffer = ft_strnew(BUFF_SIZE);
	if (!(fd = open(e->path, O_RDONLY)))
		exit(0);
	while ((ret = read(fd, buffer, BUFF_SIZE)))
		i += ret;
	close(fd);
	free(buffer);
	return (i);
}
