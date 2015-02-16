/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 18:29:38 by vchaillo          #+#    #+#             */
/*   Updated: 2015/02/16 03:31:10 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_head_strings(t_env *e)
{
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
	if (e->menu == ON)
		mlx_string_put(e->mlx, e->win, TEXT_W, TEXT_H, WHITE, \
			"HIDE COMMANDS");
	else
		mlx_string_put(e->mlx, e->win, TEXT_W, TEXT_H, WHITE, \
			"SHOW COMMANDS");
	if (e->menu == ON)
	{
		mlx_string_put(e->mlx, e->win, (TEXT_W / 2), (TEXT_H * 3), YELLOW, \
				"Zoom + : +");
		mlx_string_put(e->mlx, e->win, (TEXT_W / 2), (TEXT_H * 4), YELLOW, \
				"Zoom - : -");
		mlx_string_put(e->mlx, e->win, (TEXT_W / 2), (TEXT_H * 5), YELLOW, \
				"Peaks + : num+");
		mlx_string_put(e->mlx, e->win, (TEXT_W / 2), (TEXT_H * 6), YELLOW, \
				"Peaks - : num-");
		mlx_string_put(e->mlx, e->win, (TEXT_W / 2), (TEXT_H * 7), YELLOW, \
				"Isometric : num1");
		mlx_string_put(e->mlx, e->win, (TEXT_W / 2), (TEXT_H * 8), YELLOW, \
				"Parallel : num2");
		mlx_string_put(e->mlx, e->win, (TEXT_W / 2), (TEXT_H * 9), YELLOW, \
				"Reset Display : num0");
		mlx_string_put(e->mlx, e->win, (TEXT_W / 2), (TEXT_H * 10), YELLOW, \
				"Rotation left : l");
		mlx_string_put(e->mlx, e->win, (TEXT_W / 2), (TEXT_H * 11), YELLOW, \
				"Rotation right : r");
	}
}
