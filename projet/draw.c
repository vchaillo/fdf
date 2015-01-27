/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 02:20:44 by valentin          #+#    #+#             */
/*   Updated: 2015/01/27 19:16:19 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		draw_map(t_env *e)
{
	t_point		p1;
	t_point		p2;

	p1.x = 100;
	p1.y = WIN_H - 100;
	p2.x = WIN_W - 100;
	p2.y = 100;
	draw_line(p1.x, p1.y, p2.x, p2.y, e);
	return (0);
}

int		draw_line(int x1, int y1, int x2, int y2, t_env *e)
{
	int x;

	x = x1;
	while (x <= x2)
	{
		mlx_pixel_put(e->mlx, e->win, x, y1 + ((y2 - y1) * (x - x1)) / (x2 - x1), ORANGE);
		x++;
	}
	return (0);
}
