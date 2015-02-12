/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 18:37:00 by vchaillo          #+#    #+#             */
/*   Updated: 2015/02/12 03:28:05 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calculate(t_point *p, t_env *e)
{
	if (e->proj_mode == ISO)
		calculate_iso(p, e);
	else if (e->proj_mode == PARA)
		calculate_para(p, e);
	else if (e->proj_mode == CONIC)
		calculate_conic(p, e);
}

void	calculate_iso(t_point *p, t_env *e)
{
	p->x2d = (p->x * 50) - (e->max_w / 4 * 50);
	p->y2d = (p->y * 50) - (e->max_h / 4 * 50);
	p->x2d = p->x2d - p->y2d + WIN_W / 2;
	p->y2d = (-p->z * 15) + (p->x * 50) * 0.5 + p->y2d * 0.5 + WIN_H / 3;
	(void)e;
}

void	calculate_para(t_point *p, t_env *e)
{
	(void)e;
	(void)p;
}

void	calculate_conic(t_point *p, t_env *e)
{
	(void)e;
	(void)p;
}
