/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 18:29:38 by vchaillo          #+#    #+#             */
/*   Updated: 2015/02/16 03:16:21 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_head_strings(t_env *e)
{
	mlx_string_put(e->mlx, e->win, (CASE_W) * 7 + TEXT_W, TEXT_H, WHITE, \
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
	}
}
