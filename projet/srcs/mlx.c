/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 19:31:37 by vchaillo          #+#    #+#             */
/*   Updated: 2015/02/12 04:24:48 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
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
	erase_image(e);
	ft_putnbr(keycode);
	ft_putchar('\n');
	return (0);
}

void	start_mlx(char *path)
{
	t_env	e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIN_W, WIN_H, "fdf");
	e.img = mlx_new_image(e.mlx, WIN_W, WIN_H);
	e.color_mode = STD;
	e.proj_mode = ISO;
	e.path = ft_strdup(path);
	e.map = create_map(&e);
	e.data = mlx_get_data_addr(e.img, &(e.bpp), &(e.size), &(e.endian));
	calculate(&e);
	draw_map(&e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
}
