/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 06:54:32 by vchaillo          #+#    #+#             */
/*   Updated: 2015/02/15 21:17:03 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_menu(t_env *e)
{
	int		x;
	int		y;

	y = CASE_H + 1;
	while (y < WIN_H)
	{
		x = 1;
		while (x < CASE_W)
		{
			fill_pixel(e, DARK_GREY, x, y);
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
	while (y < CASE_H)
	{
		x = 1;
		while (x < WIN_W)
		{
			if (!(x % CASE_W))
				fill_pixel(e, BLACK, x, y);
			else
				fill_pixel(e, DARK_GREY, x, y);
			x++;
		}
		y++;
	}
}
