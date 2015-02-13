/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 06:54:32 by vchaillo          #+#    #+#             */
/*   Updated: 2015/02/13 16:49:05 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_main_menu(t_env *e)
{
	int		x;
	int		y;

	y = 1;
	while (y < WIN_H)
	{
		x = 1;
		while (x < WIN_W)
		{
			if (x % 20 == 0 && y % 20 == 0)
				fill_pixel(e, YELLOW, x, y);
			else
				fill_pixel(e, BLACK, x, y);
			x++;
		}
		y++;
	}
}

void	draw_header(t_env *e)
{
	int		x;
	int		y;

	y = 1;
	while (y < WIN_H / 20)
	{
		x = 1;
		while (x < WIN_W)
		{
			if (!(x % (WIN_W / 10)))
				fill_pixel(e, BLACK, x, y);
			else
				fill_pixel(e, DARK_GREY, x, y);
			x++;
		}
		y++;
	}
}
