/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 19:31:37 by vchaillo          #+#    #+#             */
/*   Updated: 2015/02/12 08:00:12 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_string_put(e->mlx, e->win, 20, 20, YELLOW, \
			"FDF by vchaillo, Project of 42");
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 65307)
		exit (0);
	if (keycode == 48)
		e->color_mode = STD;
	if (keycode == 49)
		e->color_mode = FRENCH;
	if (keycode == 65457)
		e->proj_mode = ISO;
	if (keycode == 65458)
		e->proj_mode = PARA;
	if (keycode == 65361)
		e->move_lr -= 30;
	if (keycode == 65363)
		e->move_lr += 30;
	if (keycode == 65364)
		e->move_ud += 30;
	if (keycode == 65362)
		e->move_ud -= 30;
	if (keycode == 65451)
		e->peaks += 5;
	if (keycode == 65453)
		e->peaks -= 5;
	if (keycode == 61)
		e->zoom += 10;
	if (keycode == 45)
		e->zoom -= 10;
	if (keycode == 65293)
		vanilla_mode(e);
	erase_image(e);
	ft_putnbr(keycode);
	ft_putchar('\n');
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
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
}
