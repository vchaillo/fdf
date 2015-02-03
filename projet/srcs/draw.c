/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 02:20:44 by valentin          #+#    #+#             */
/*   Updated: 2015/02/03 19:16:35 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_map(t_env *e)
{
	t_point	p1;
	t_point	p2;

	p1.x = 100;
	p1.y = 100;
	p2.x = WIN_W - 100;
	p2.y = WIN_H - 100;
	draw_line_img(p1, p2, e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

void	draw_line_img(t_point p1, t_point p2, t_env *e)
{
	int		x;
	int		color;

	x = p1.x;
	while (x <= p2.x)
	{
		if (e->color_mode == 0)
			color = ORANGE;
		if (e->color_mode == 1)
			color = select_french_color(x, p1.y);
		put_color_on_pixel(e, color, x, \
			p1.y + ((p2.y - p1.y) * (x - p1.x)) / (p2.x - p1.x));
		x++;
	}
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
