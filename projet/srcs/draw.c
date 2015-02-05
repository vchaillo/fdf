/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 02:20:44 by valentin          #+#    #+#             */
/*   Updated: 2015/02/05 19:45:53 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_map(t_env *e)
{
	t_point	p1;		//test pour dx > dy
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


	t_point	p5;		//test pour dy > dx
	t_point	p6;
	t_point	p7;		//test pour dy > dx
	t_point	p8;

	p5.x = WIN_W / 2 - 100;
	p5.y = 100;
	p6.x = WIN_W / 2 + 100;
	p6.y = WIN_H - 100;
	p7.x = WIN_W / 2 + 100;
	p7.y = 100;
	p8.x = WIN_W / 2 - 100;
	p8.y = WIN_H - 100;

	draw_lines(p2, p1, e);
	draw_lines(p3, p4, e);
	draw_lines(p6, p5, e);
	draw_lines(p8, p7, e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

void	draw_lines(t_point p1, t_point p2, t_env *e)
{
	int		dx;
	int		dy;

	if ((dx = p2.x - p1.x) < 0)
		dx *= -1;
	if ((dy = p2.y - p1.y) < 0)
		dy *= -1;
	if (dx >= dy)
	{
		if (p1.x < p2.x)
			draw_line_1(p1, p2, e);
		else
			draw_line_1(p2, p1, e);
	}
	else
	{
		if (p1.y <= p2.y)
			draw_line_2(p1, p2, e);
		else
			draw_line_2(p2, p1, e);
	}
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
