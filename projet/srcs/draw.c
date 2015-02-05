/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 02:20:44 by valentin          #+#    #+#             */
/*   Updated: 2015/02/05 11:41:44 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_map(t_env *e)
{
	t_point	p1;
	t_point	p2;
	t_point	p3;
	t_point	p4;

	p1.x = 100;
	p1.y = 100;
	p2.x = WIN_W - 100;
	p2.y = WIN_H - 100;
	p3.x = 100;
	p3.y = WIN_H - 100;
	p4.x = WIN_W - 100;
	p4.y = 100;
	draw_lines(p1, p2, e);
	draw_lines(p3, p4, e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

void	draw_lines(t_point p1, t_point p2, t_env *e)
{
	int		dx;
	int		dy;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	if (dx > dy)
		draw_line_1(p1, p2, e);
}

void	fill_pixel(t_env *e, int color, int x, int y)
{
	int		i;

	i = x * 4 + y * e->size;
	e->data[i] = color % 256;
	color /= 256;
	e->data[i + 1] = color % 256;
	color /= 256;
	e->data[i + 2] = color % 256;
}
