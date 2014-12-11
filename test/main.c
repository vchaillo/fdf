/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 23:35:21 by vchaillo          #+#    #+#             */
/*   Updated: 2014/12/12 00:00:15 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>

typedef struct		s_env
{
	void			*mlx;
	void			*win;
}					t_env;

void	draw(void *mlx, void *win)
{
	int				x;
	int				y;

	y = 100;
	while (y != 200)
	{
		x = 100;
		while (x != 200)
		{
			mlx_pixel_put(mlx, win, x, y, 0x323232);
			x++;
		}
		y++;
	}
}

int		expose_hook(t_env *e)
{
	draw(e->mlx, e->win);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 65307)
		exit(0);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == 1 && x > 100 && x < 200 && y > 100 && y < 200)
		exit(0);
	return (0);
}

int		main(int ac, char **av)
{
	t_env			e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 1280, 720, "mlx powa!");
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
