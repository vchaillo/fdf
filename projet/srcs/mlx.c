/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 19:31:37 by vchaillo          #+#    #+#             */
/*   Updated: 2015/02/16 03:31:37 by valentin         ###   ########.fr       */
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
	if (keycode == 65307)
		exit (0);
	if (keycode == 48 || keycode == 224)
		e->color_mode = STD;
	if (keycode == 49 || keycode == 38)
		e->color_mode = FRENCH;
	if (keycode == 50 || keycode == 233)
		e->color_mode = WHITE_BLUE;
	if (/*keycode == 50 || */keycode == 34)
		e->color_mode = EARTH;
	if (keycode == 65457 || keycode == 65436)
		e->proj_mode = ISO;
	if (keycode == 65458 || keycode == 65433)
		e->proj_mode = PARA;
	if (keycode == 65361 || keycode == 65363)
		move_lr(e, keycode);
	if (keycode == 65364 || keycode == 65362)
		move_ud(e, keycode);
	if (keycode == 65451 || keycode == 65453)
		change_peaks(e, keycode);
	if (keycode == 61 || keycode == 45)
		change_zoom(e, keycode);
	if (keycode == 65456 || keycode == 65438)
		vanilla_mode(e);
	erase_image(e);
	ft_putnbr(keycode);
	ft_putchar('\n');
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == 1 && y < CASE_H && x > 0 && x < CASE_W)
	{
		if (e->menu == ON)
			e->menu = OFF;
		else
			e->menu = ON;
	}
	if (button == 1 && y < CASE_H && x > CASE_W * 7 && x < CASE_W * 8)
		e->proj_mode = PARA;
	if (button == 1 && y < CASE_H && x > CASE_W * 8 && x < CASE_W * 9)
		e->proj_mode = ISO;
	if (button == 1 && y < CASE_H && x > CASE_W * 9 && x < CASE_W * 10)
		vanilla_mode(e);
	erase_image(e);
	return (0);
}

void	start_mlx(char *path)
{
	t_env	e;

	if (!(e.mlx = mlx_init()))
		exit (0);
	e.win = mlx_new_window(e.mlx, WIN_W, WIN_H, "fdf");
	e.img = mlx_new_image(e.mlx, WIN_W, IMG_H);
	e.img_head = mlx_new_image(e.mlx, WIN_W, HEAD_H);
	e.path = ft_strdup(path);
	e.map = create_map(&e);
	vanilla_mode(&e);
	e.data = mlx_get_data_addr(e.img, &(e.bpp), &(e.size), &(e.endian));
	e.data_head = mlx_get_data_addr(e.img_head, &(e.bpp), &(e.size_head), &(e.endian));
	calculate(&e);
	draw_map(&e);
	draw_header(&e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_hook(e.win, 3, 3, key_hook, &e);
	mlx_loop(e.mlx);
}
