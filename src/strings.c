/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 18:29:38 by vchaillo          #+#    #+#             */
/*   Updated: 2017/04/03 03:48:05 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_head_strings(t_env *e)
{
	mlx_string_put(e->mlx, e->win, ((CASE_W) * 1) + TEXT_OFFSET_W,
		TEXT_OFFSET_H, WHITE, " FRENCH COLOR");
	mlx_string_put(e->mlx, e->win, ((CASE_W) * 2) + TEXT_OFFSET_W,
		TEXT_OFFSET_H, WHITE, "  MARS COLOR");
	mlx_string_put(e->mlx, e->win, ((CASE_W) * 3) + TEXT_OFFSET_W,
		TEXT_OFFSET_H, WHITE, " EARTH COLOR");
	mlx_string_put(e->mlx, e->win, ((CASE_W) * 4) + TEXT_OFFSET_W,
		TEXT_OFFSET_H, WHITE, "STANDARD COLOR");
	mlx_string_put(e->mlx, e->win, ((CASE_W) * 5) + TEXT_OFFSET_W,
		TEXT_OFFSET_H, WHITE, "ROTATION LEFT");
	mlx_string_put(e->mlx, e->win, ((CASE_W) * 6) + TEXT_OFFSET_W,
		TEXT_OFFSET_H, WHITE, "ROTATION RIGHT");
	mlx_string_put(e->mlx, e->win, ((CASE_W) * 7) + TEXT_OFFSET_W,
		TEXT_OFFSET_H, WHITE, "PARALLEL VIEW");
	mlx_string_put(e->mlx, e->win, ((CASE_W) * 8) + TEXT_OFFSET_W,
		TEXT_OFFSET_H, WHITE, "ISOMETRIC VIEW");
	mlx_string_put(e->mlx, e->win, ((CASE_W) * 9) + TEXT_OFFSET_W,
		TEXT_OFFSET_H, WHITE, "RESET DISPLAY");
}

void	put_menu_strings(t_env *e)
{
	if (e->menu == ON)
	{
		mlx_string_put(e->mlx, e->win, TEXT_OFFSET_W, TEXT_OFFSET_H,
			DARK_GREY, "SHOW COMMANDS");
		mlx_string_put(e->mlx, e->win, TEXT_OFFSET_W, TEXT_OFFSET_H,
			ORANGE, "HIDE COMMANDS");
	}
	else
	{
		mlx_string_put(e->mlx, e->win, TEXT_OFFSET_W, TEXT_OFFSET_H,
			DARK_GREY, "HIDE COMMANDS");
		mlx_string_put(e->mlx, e->win, TEXT_OFFSET_W, TEXT_OFFSET_H,
			ORANGE, "SHOW COMMANDS");
	}
	if (e->menu == ON)
	{
		put_strings_1(e);
		put_strings_2(e);
	}
}

void	put_strings_1(t_env *e)
{
	mlx_string_put(e->mlx, e->win, TEXT_OFFSET_W - 10,
		CASE_H * 1 + TEXT_OFFSET_H, ORANGE, "Zoom + : +");
	mlx_string_put(e->mlx, e->win, TEXT_OFFSET_W - 10,
		CASE_H * 2 + TEXT_OFFSET_H, ORANGE, "Zoom - : -");
	mlx_string_put(e->mlx, e->win, TEXT_OFFSET_W - 10,
		CASE_H * 3 + TEXT_OFFSET_H, ORANGE, "Peaks + : num+");
	mlx_string_put(e->mlx, e->win, TEXT_OFFSET_W - 10,
		CASE_H * 4 + TEXT_OFFSET_H, ORANGE, "Peaks - : num-");
	mlx_string_put(e->mlx, e->win, TEXT_OFFSET_W - 10,
		CASE_H * 5 + TEXT_OFFSET_H, ORANGE, "Isometric : num1");
	mlx_string_put(e->mlx, e->win, TEXT_OFFSET_W - 10,
		CASE_H * 6 + TEXT_OFFSET_H, ORANGE, "Parallel : num2");
	mlx_string_put(e->mlx, e->win, TEXT_OFFSET_W - 10,
		CASE_H * 7 + TEXT_OFFSET_H, ORANGE, "Reset : num0");
}

void	put_strings_2(t_env *e)
{
	mlx_string_put(e->mlx, e->win, TEXT_OFFSET_W - 10,
		CASE_H * 8 + TEXT_OFFSET_H, ORANGE, "Rotation left : l");
	mlx_string_put(e->mlx, e->win, TEXT_OFFSET_W - 10,
		CASE_H * 9 + TEXT_OFFSET_H, ORANGE, "Rotation right : r");
	mlx_string_put(e->mlx, e->win, TEXT_OFFSET_W - 10,
		CASE_H * 10 + TEXT_OFFSET_H, ORANGE, "Standard color : 0");
	mlx_string_put(e->mlx, e->win, TEXT_OFFSET_W - 10,
		CASE_H * 11 + TEXT_OFFSET_H, ORANGE, "French color : 1");
	mlx_string_put(e->mlx, e->win, TEXT_OFFSET_W - 10,
		CASE_H * 12 + TEXT_OFFSET_H, ORANGE, "Mars color : 2");
	mlx_string_put(e->mlx, e->win, TEXT_OFFSET_W - 10,
		CASE_H * 13 + TEXT_OFFSET_H, ORANGE, "Earth color : 3");
}
