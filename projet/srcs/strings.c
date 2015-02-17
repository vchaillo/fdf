/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 18:29:38 by vchaillo          #+#    #+#             */
/*   Updated: 2015/02/17 04:27:38 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_head_strings(t_env *e)
{
	mlx_string_put(e->mlx, e->win, (CASE_W * 1) + TEXT_W, TEXT_H, WHITE, \
			"FRENCH COLOR");
	mlx_string_put(e->mlx, e->win, (CASE_W * 2) + TEXT_W, TEXT_H, WHITE, \
			"WHITE BLUE COLOR");
	mlx_string_put(e->mlx, e->win, (CASE_W * 3) + TEXT_W, TEXT_H, WHITE, \
			"EARTH COLOR");
	mlx_string_put(e->mlx, e->win, (CASE_W * 4) + TEXT_W, TEXT_H, WHITE, \
			"STANDARD COLOR");
	mlx_string_put(e->mlx, e->win, (CASE_W * 5) + TEXT_W, TEXT_H, WHITE, \
			"ROTATION LEFT");
	mlx_string_put(e->mlx, e->win, (CASE_W * 6) + TEXT_W, TEXT_H, WHITE, \
			"ROTATION RIGHT");
	mlx_string_put(e->mlx, e->win, (CASE_W * 7) + TEXT_W, TEXT_H, WHITE, \
			"PARALLEL VIEW");
	mlx_string_put(e->mlx, e->win, (CASE_W * 8) + TEXT_W, TEXT_H, WHITE, \
			"ISOMETRIC VIEW");
	mlx_string_put(e->mlx, e->win, (CASE_W * 9) + TEXT_W, TEXT_H, WHITE, \
			"RESET DISPLAY");
}

void	put_menu_strings(t_env *e)
{
/*	if (e->menu == ON)
		mlx_string_put(e->mlx, e->win, TEXT_W, TEXT_H, ORANGE, \
			"HIDE COMMANDS");
	else*/
		mlx_string_put(e->mlx, e->win, TEXT_W, TEXT_H, ORANGE, \
			"SHOW COMMANDS");
	if (e->menu == ON)
	{
		put_strings_1(e);
		put_strings_2(e);
	}
}

void	put_strings_1(t_env *e)
{
		mlx_string_put(e->mlx, e->win, (TEXT_W / 2), (TEXT_H * 3), ORANGE, \
				"Zoom + : +");
		mlx_string_put(e->mlx, e->win, (TEXT_W / 2), (TEXT_H * 4), ORANGE, \
				"Zoom - : -");
		mlx_string_put(e->mlx, e->win, (TEXT_W / 2), (TEXT_H * 5), ORANGE, \
				"Peaks + : num+");
		mlx_string_put(e->mlx, e->win, (TEXT_W / 2), (TEXT_H * 6), ORANGE, \
				"Peaks - : num-");
		mlx_string_put(e->mlx, e->win, (TEXT_W / 2), (TEXT_H * 7), ORANGE, \
				"Isometric : num1");
		mlx_string_put(e->mlx, e->win, (TEXT_W / 2), (TEXT_H * 8), ORANGE, \
				"Parallel : num2");
		mlx_string_put(e->mlx, e->win, (TEXT_W / 2), (TEXT_H * 9), ORANGE, \
				"Reset Display : num0");
}

void	put_strings_2(t_env *e)
{
		mlx_string_put(e->mlx, e->win, (TEXT_W / 2), (TEXT_H * 10), ORANGE, \
				"Rotation left : l");
		mlx_string_put(e->mlx, e->win, (TEXT_W / 2), (TEXT_H * 11), ORANGE, \
				"Rotation right : r");
		mlx_string_put(e->mlx, e->win, (TEXT_W / 2), (TEXT_H * 12), ORANGE, \
				"Standard color : 0");
		mlx_string_put(e->mlx, e->win, (TEXT_W / 2), (TEXT_H * 13), ORANGE, \
				"french color : 1");
		mlx_string_put(e->mlx, e->win, (TEXT_W / 2), (TEXT_H * 14), ORANGE, \
				"White blue color : 2");
		mlx_string_put(e->mlx, e->win, (TEXT_W / 2), (TEXT_H * 15), ORANGE, \
				"Earth color : 3");
}
