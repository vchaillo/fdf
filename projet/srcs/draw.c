/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 02:20:44 by valentin          #+#    #+#             */
/*   Updated: 2015/01/28 15:09:39 by vchaillo         ###   ########.fr       */
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
	draw_line(p1, p2, e);
	return (0);
}

int		draw_line(t_point p1, t_point p2, t_env *e)
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
}
