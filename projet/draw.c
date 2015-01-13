/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 02:20:44 by valentin          #+#    #+#             */
/*   Updated: 2015/01/13 19:20:55 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		draw_map(t_env *e)
{
	draw_1(e);
//	sleep(1);
//	draw_2(e);
	return (0);
}

void	draw_1(t_env *e)
{
	int	x;
	int	y;

	y = 100;
	while (y < WIN_H - 100)
	{
		x = 100;
		while (x < WIN_W - 100)
		{
			mlx_pixel_put(e->mlx, e->win, x, y, YELLOW);
			x++;
		}
		y++;
	}
}

void	draw_2(t_env *e)
{
	int	x;
	int	y;

	y = 100;
	while (y < WIN_H - 100)
	{
		x = 100;
		while (x < WIN_W - 100)
		{
			mlx_pixel_put(e->mlx, e->win, x, y, BLUE);
			x++;
		}
		y++;
	}
}
