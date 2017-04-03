/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 19:31:06 by vchaillo          #+#    #+#             */
/*   Updated: 2017/04/03 03:15:37 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				get_nb_map_lines(t_env *e)
{
	char		*line;
	int			nb_lines;
	int			fd;

	if ((fd = open(e->path, O_RDONLY)) == -1)
		open_error(e);
	nb_lines = 0;
	while (get_next_line(fd, &line) == 1)
		nb_lines++;
	return (nb_lines);
}

int				get_tab_len(char **tab)
{
	int			len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
}
