/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 19:34:55 by vchaillo          #+#    #+#             */
/*   Updated: 2014/12/15 21:42:57 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_map(t_env *e)
{
	int		fd;
	int		i;
	int		tab_len;
	char	*line;
	int		**grid;

	i = 0;
	line = NULL;
	if (!(fd = open(e->path, O_RDONLY)))
		exit(0);
	tab_len = get_tab_len(e);
	if (!(grid = (int **)malloc(sizeof(int *) * tab_len)))
		exit(0);
	while (get_next_line(fd, &line) == 1)
	{
		grid[i] = get_int_tab(line);
		i++;
	}
	i = 0;
//	while (grid[i])
//	{
//		ft_putendl(grid[i]);
//		i++;
//	}
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

int		*get_int_tab(char *line)
{
	int		*str;
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_strsplit(line, ' ');
	while (tmp[i])
	{
		str[i] = ft_atoi(tmp[i]);
		i++;
	}
	return (str);
}
