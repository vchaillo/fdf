/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 18:47:12 by vchaillo          #+#    #+#             */
/*   Updated: 2015/02/15 18:23:08 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line_1(t_point p1, t_point p2, t_env *e)
{
	int	x;
	int	ycal;
	int	dx;
	int	dy;
	int	color;

	dx = p2.x2d - p1.x2d;
	dy = p2.y2d - p1.y2d;
	x = p1.x2d;
	while (x < p2.x2d)
	{
		ycal = p1.y2d + (dy * (x - p1.x2d)) / dx;
		if (x < WIN_W && x > 0 && ycal < WIN_H && ycal > 0)
		{
			color = color_mode(e->color_mode, x, p1, p2);
			fill_pixel(e, color, x, ycal);
		}
		x++;
	}
}

void	draw_line_2(t_point p1, t_point p2, t_env *e)
{
	int	y;
	int	xcal;
	int	dx;
	int	dy;
	int	color;

	dx = p2.x2d - p1.x2d;
	dy = p2.y2d - p1.y2d;
	y = p1.y2d;
	while (y < p2.y2d)
	{
		xcal = p1.x2d + (dx * (y - p1.y2d)) / dy;
		if (xcal < WIN_W && xcal > 0 && y < WIN_H && y > 0)
		{
			color = color_mode(e->color_mode, xcal, p1, p2);
			fill_pixel(e, color, xcal, y);
		}
		y++;
	}
}
