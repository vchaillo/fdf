/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 02:20:44 by valentin          #+#    #+#             */
/*   Updated: 2015/01/28 18:12:52 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		draw_map(t_env *e)
{
	draw_image(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

int		draw_image(t_env *e)
{
	int		x;
	int		y;
	int		color;

	y = 0;
	while (y <= WIN_H)
	{
		x = 0;
		while (x <= WIN_W)
		{
			color = select_a_color(x, y);
			put_color_on_pixel(e, color, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

void	put_color_on_pixel(t_env *e, int color, int x, int y)
{
	int		i;

	i = x * 4 + y * e->size;
	e->data[i] = color % 256;
	color /= 256;
	e->data[i + 1] = color % 256;
	color /= 256;
	e->data[i + 2] = color % 256;
}

int		select_a_color(int x, int y)
{
	int		color;

	(void)y;
	color = BLUE;
	if (x >= WIN_W / 3)
		color = WHITE;
	if (x >= (WIN_W / 3) * 2)
		color = RED;
	return (color);
}

/*int		draw_line(t_point p1, t_point p2, t_env *e)
{
	int x;

	x = p1.x;
	while (x <= p2.x)
	{
		mlx_pixel_put(e->mlx, e->win, x,\
			p1.y + ((p2.y - p1.y) * (x - p1.x)) / (p2.x - p1.x), ORANGE);
		x++;
	}
	return (0);
}*/
