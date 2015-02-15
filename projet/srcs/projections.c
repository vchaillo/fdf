/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 18:37:00 by vchaillo          #+#    #+#             */
/*   Updated: 2015/02/15 23:09:56 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calculate(t_env *e)
{
	int		i;
	int		j;

	i = 0;
	while (i < e->max_h)
	{
		j = 0;
		while (j < e->max_w)
		{
			if (e->proj_mode == ISO)
				calculate_iso(&(e->map[i][j]), e);
			else if (e->proj_mode == PARA)
				calculate_para(&(e->map[i][j]), e);
			else if (e->proj_mode == CONIC)
				calculate_conic(&(e->map[i][j]), e);
			j++;
		}
		i++;
	}
}

void	calculate_iso(t_point *p, t_env *e)
{
	p->x2d = (p->x * e->zoom) - (e->max_w / 2 * e->zoom);
	p->y2d = (p->y * e->zoom) - (e->max_h / 2 * e->zoom);
	p->x2d = p->x2d - p->y2d + WIN_W / 2 + e->move_lr;
	p->y2d = (-p->z * e->peaks) + (p->x * e->zoom) * 0.5 + p->y2d * 0.5 \
		+ WIN_H / 3 + e->move_ud;
}

void	calculate_para(t_point *p, t_env *e)
{
	p->x2d = (p->x * e->zoom) - (e->max_w / 2 * e->zoom);
	p->y2d = (p->y * e->zoom) - (e->max_h / 2 * e->zoom);
	p->x2d = p->x2d - (p->z * e->peaks) + WIN_W / 2 + e->move_lr;
	p->y2d = p->y2d + -1 * 0.5 * (p->z * e->peaks) + WIN_H / 3 + e->move_ud;
}

void	calculate_conic(t_point *p, t_env *e)
{
	(void)p;
	(void)e;
}

void	vanilla_mode(t_env *e)
{
	e->color_mode = STD;
	e->proj_mode = ISO;
	e->move_ud = 0;
	e->move_lr = 0;
	e->peaks = 15;
	e->zoom = (WIN_W / e->max_w / 8) + (WIN_H / e->max_h / 3);
	e->menu = OFF;
}
