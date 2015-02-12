/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 06:54:32 by vchaillo          #+#    #+#             */
/*   Updated: 2015/02/12 07:53:01 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_main_menu(t_env *e)
{
	int		x;
	int		y;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			if (x % 20 == 0 && y % 20 == 0)
				fill_pixel(e, YELLOW, x, y);
			else
				fill_pixel(e, DARK_GREY, x, y);
			x++;
		}
		y++;
	}
}
