/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 14:46:19 by valentin          #+#    #+#             */
/*   Updated: 2014/12/15 20:29:17 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int	get_len_tab(t_env *e)
{
	int	fd;
	int	i;
	int	ret;
	char	*buf;
	
	
	i = 0;
	buf = ft_strnew(BUFF_SIZE);
	if (!(fd = open(e->path, O_RDONLY)))
		exit(0);
	while (ret = read(fd, buf, BUFF_SIZE))
	{
		i+= ret;
	}
	close(fd);
	free(buf);
	return(i);
}

char	**create_map(t_env *e)
{
	int	fd;
	int	i;
	int	j;
	int	len_tab;
	char 	*line;
	char 	**tmp;
	char	**grid;

	i = 0;
	line = NULL;
	len_tab = get_len_tab(e);
	if (!(fd = open(e->path, O_RDONLY)))
		exit(0);
	while (get_next_line(fd, &line) == 1)
	{
		tmp = ft_strsplit(line, ' ');
		j = 0;
		grid[i] = tmp[j++];
		while (tmp[j])
		{
			grid[i] = ft_strjoin(grid[i], tmp[j]);
			j++;
		}
		i++;
	}
	ft_memdel((void **)tmp);
	return (grid);
}
