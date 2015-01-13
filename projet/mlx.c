/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 19:31:37 by vchaillo          #+#    #+#             */
/*   Updated: 2015/01/13 21:00:28 by vchaillo         ###   ########.fr       */
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
	(void)e;
	if (keycode == 65307)
		exit (0);
	return (0);
}

int		start_mlx(char *path)
{
	t_env	e;
	int		i;
	int		j;

	i = 0;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIN_W, WIN_H, "fdf");
	e.path = ft_strdup(path);
	e.map = create_map(&e);
	while (e.map[i])
	{
		j = 0;
		while (e.map[i][j].z)
		{
			ft_putnbr(e.map[i][j].z);
			ft_putstr(", ");
			j++;
		}
		i++;
	}
	/*ft_putstr("La case 1, 4 : ");
	ft_putnbr(e.map[1][4].z);
	ft_putstr(", ");
	ft_putnbr(e.map[1][4].y);
	ft_putstr(", ");
	ft_putnbr(e.map[1][4].x);
	ft_putchar('\n');*/

	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
