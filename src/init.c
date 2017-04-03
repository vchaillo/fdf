/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 08:05:20 by valentin          #+#    #+#             */
/*   Updated: 2017/04/03 08:11:26 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_env(t_env *e)
{
	e->map = parse_map(e);
	vanilla_mode(e);
	e->data_head = mlx_get_data_addr(e->img_head, &(e->bpp), &(e->size_head),
		&(e->endian));
	draw_header(e);
}

void	vanilla_mode(t_env *e)
{
	e->color_mode = STD;
	e->proj_mode = ISO;
	e->move_ud = 0;
	e->move_lr = 0;
	e->peaks = 5;
	e->zoom = (WIN_W / e->max_w / 8) + (WIN_H / e->max_h / 3);
	e->menu = OFF;
}
