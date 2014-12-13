/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 17:32:07 by valentin          #+#    #+#             */
/*   Updated: 2014/12/13 04:22:37 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

void	erase_line(t_env *e)
{
	int	y;

	y = 650;
	while (y <= 700)
	{
		mlx_pixel_put(e->mlx, e->win, e->x_rect - 50, y, BLACK);
		y++;
	}
}

void	draw_line(t_env *e)
{
	int	y;

	y = 650;
	while (y <= 700)
	{
		mlx_pixel_put(e->mlx, e->win, e->x_rect, y, GREEN);
		y++;
	}
}

void	move(t_env *e)
{
	while (e->x_rect < 1260)
	{
		draw_line(e);
		erase_line(e);
		usleep(10000);
		e->x_rect++;
	}
}

void	draw_rect(void *mlx, void *win, t_env *e)
{
	int	y;

	y = 650;
	while (y <= 700)
	{
		e->x_rect = 20;
		while (e->x_rect <= 50)
		{
			mlx_pixel_put(e->mlx, e->win, e->x_rect, y, GREEN);
			e->x_rect++;
		}
		y++;
	}
	move(e);
}

int	expose_hook(t_env *e)
{
	draw_rect(e->mlx, e->win, e);
	return (0);
}

int	key_hook(int keycode, t_env *e)
{
	printf("keycode = %d\n", keycode);
	if (keycode == 65307)
		exit(0);
	if (keycode == 113)
		exit(0);
	if (keycode == 114)
		exit(0);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_env *e)
{
	printf("button = %d - (%d;%d)\n", button, x, y);
	return (0);
}

int	load_window(void)
{
	t_env	e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 1280, 720, "prog_mlx");
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
