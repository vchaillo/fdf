/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 20:03:20 by vchaillo          #+#    #+#             */
/*   Updated: 2014/12/12 00:00:34 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct		s_env
{
	void	*mlx;
	void	*win;
}					t_env;

void	draw(void *mlx, void *win)
{
	int		x;
	int		y;

	y = 500;
	while (y != 600)
	{
		x = 200;
		while (x != 300)
		{
			mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}
}

int		key_hook(int keycode, t_env *e)
{
	printf("key : %d\n", keycode);
	if (keycode == 65307)
		exit(0);
	return (0);
}

int		expose_hook(t_env *e)
{
	draw(e->mlx, e->win);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 2560, 1310, "mlx_soft");
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.mlx, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
