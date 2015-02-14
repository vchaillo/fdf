/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 19:31:37 by vchaillo          #+#    #+#             */
/*   Updated: 2015/02/14 23:14:07 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		expose_hook(t_env *e)
{
	draw_header(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	strings(e);
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
	if (keycode == 233)
		e->color_mode = WHITE_BLUE;
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
	if (keycode == 65438)
		vanilla_mode(e);
	erase_image(e);
	ft_putnbr(keycode);
	ft_putchar('\n');
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == 1 && y < CASE_H && x > CASE_W * 10)
		vanilla_mode(e);
	if (button == 1 && y < CASE_H && x > CASE_W * 8 && x < CASE_W * 9)
		e->proj_mode = ISO;
	if (button == 1 && y < CASE_H && x > CASE_W * 7 && x < CASE_W * 8)
		e->proj_mode = PARA;
	erase_image(e);
	return (0);
}

void	start_mlx(char *path)
{
	t_env	e;

	if (!(e.mlx = mlx_init()))
		exit (0);
	e.win = mlx_new_window(e.mlx, WIN_W, WIN_H, "fdf");
	e.img = mlx_new_image(e.mlx, WIN_W, WIN_H);
	vanilla_mode(&e);
	e.path = ft_strdup(path);
	e.map = create_map(&e);
	e.data = mlx_get_data_addr(e.img, &(e.bpp), &(e.size), &(e.endian));
	calculate(&e);
	draw_main_menu(&e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
}
