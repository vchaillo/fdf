/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 17:32:07 by valentin          #+#    #+#             */
/*   Updated: 2014/12/17 02:53:57 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int	expose_hook(t_env *e)
{
	draw_map(e);
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

int	mlx_start(char *path)
{
	t_env	e;
	int	i;

	i = 0;
	//e.mlx = mlx_init();
	//e.win = mlx_new_window(e.mlx, 1280, 720, "prog_mlx");
	e.path = ft_strdup(path);
	e.map = create_map(&e);
//	mlx_expose_hook(e.win, expose_hook, &e);
//	mlx_key_hook(e.win, key_hook, &e);
//	mlx_mouse_hook(e.win, mouse_hook, &e);
//	mlx_loop(e.mlx);
	return (0);
}
