/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 02:20:44 by valentin          #+#    #+#             */
/*   Updated: 2015/02/10 18:22:58 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_map(t_env *e)
{
	int		i;
	int		j;

	i = 0;
	while (i < e->max_h)
	{
		j = 0;
		while (j < e->max_w)
		{
			if (j < e->max_w - 1)
				draw_lines(e->map[i][j], e->map[i][j + 1], e);
			if (i < e->max_h - 1)
				draw_lines(e->map[i][j], e->map[i + 1][j], e);
//			ft_putnbr(e->map[i][j].z);
//			ft_putchar(' ');
			j++;
		}
//		ft_putchar('\n');
		i++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

void	draw_lines(t_point p1, t_point p2, t_env *e)
{
	int		dx;
	int		dy;

	calculate(&p1, e);
	calculate(&p2, e);
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
