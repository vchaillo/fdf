/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 19:31:37 by vchaillo          #+#    #+#             */
/*   Updated: 2017/04/03 08:52:14 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, HEAD_H);
	mlx_put_image_to_window(e->mlx, e->win, e->img_head, 0, 0);
	put_menu_strings(e);
	put_head_strings(e);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == KEY_ESCAPE || keycode == KEY_ESCAPE_MAC)
		exit (0);
	if (keycode == KEY_R || keycode == KEY_R_MAC)
		vanilla_mode(e);
	color_key_hook(keycode, e);
	projection_key_hook(keycode, e);
	move_key_hook(keycode, e);
	update_image(e);
	ft_putnbr(keycode);
	ft_putchar('\n');
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == 1 && y < CASE_H && x > 0 && x < CASE_W)
		e->menu = e->menu == ON ? OFF : ON;
	else if (button == 1 && y < CASE_H && x > CASE_W * 1 && x < CASE_W * 5)
		color_mouse_hook(e, x);
	else if (button == 1 && y < CASE_H && x > CASE_W * 7 && x < CASE_W * 9)
		projection_mouse_hook(e, x);
	else if (button == 1 && y < CASE_H && x > CASE_W * 9 && x < CASE_W * 10)
		vanilla_mode(e);
	update_image(e);
	return (0);
}

void	start_mlx(char *path)
{
	t_env	e;

	if (!(e.mlx = mlx_init()))
		exit (0);
	e.path = path;
	e.win = mlx_new_window(e.mlx, WIN_W, WIN_H, "fdf");
	e.img = mlx_new_image(e.mlx, WIN_W, IMG_H);
	e.img_head = mlx_new_image(e.mlx, WIN_W, HEAD_H);
	init_env(&e);
	update_image(&e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_hook(e.win, 3, 3, key_hook, &e);
	mlx_loop(e.mlx);
}
