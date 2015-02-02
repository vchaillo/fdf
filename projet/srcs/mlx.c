/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 19:31:37 by vchaillo          #+#    #+#             */
/*   Updated: 2015/02/02 21:55:22 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		expose_hook(t_env *e)
{
	draw_map(e);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 65307)
		exit (0);
	if (keycode == 49)
	{
		e->color_mode = 1;
		draw_map(e);
	}
	if (keycode == 48)
	{
		e->color_mode = 0;
		draw_map(e);
	}
	ft_putnbr(keycode);
	ft_putchar('\n');
	return (0);
}

void	start_mlx(char *path)
{
	t_env	e;
//	int		i;
//	int		j;

//	i = 0;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIN_W, WIN_H, "fdf");
	e.img = mlx_new_image(e.mlx, WIN_W, WIN_H);
	e.color_mode = 0;
	e.path = ft_strdup(path);
	e.map = create_map(&e);
	e.data = mlx_get_data_addr(e.img, &(e.bpp), &(e.size), &(e.endian));

	/*	while (e.map[i]) //affiche tous les z pour chaque point.
	{
		j = 0;
		while (e.map[i][j].z != '\0')
		{
			ft_putnbr(e.map[i][j].z);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}

*/
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
}
