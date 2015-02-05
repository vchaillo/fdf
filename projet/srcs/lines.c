/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 18:47:12 by vchaillo          #+#    #+#             */
/*   Updated: 2015/02/05 19:45:37 by vchaillo         ###   ########.fr       */
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

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	x = p1.x;
	while (x <= p2.x)
	{
		ycal = p1.y + (dy * (x - p1.x)) / dx;
		color = select_color_mode(e->color_mode, x, ycal);
		fill_pixel(e, color, x, ycal);
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

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	y = p1.y;
	while (y <= p2.y)
	{
		xcal = p1.x + (dx * (y - p1.y)) / dy;
		color = select_color_mode(e->color_mode, xcal, y);
		fill_pixel(e, color, xcal, y);
		y++;
	}
}
