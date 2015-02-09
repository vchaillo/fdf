/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 18:37:00 by vchaillo          #+#    #+#             */
/*   Updated: 2015/02/09 21:15:16 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calculate(t_point p, t_env *e)
{
	p.x2d = p.x * 10;
	p.y2d = p.y * 10;
	if (e->proj_mode == ISO)
		calculate_iso(p, e);
	else if (e->proj_mode == PARA)
		calculate_para(p, e);
	else if (e->proj_mode == CONIC)
		calculate_conic(p, e);
}

void	calculate_iso(t_point p, t_env *e)
{
	(void)e;
	(void)p;
}
void	calculate_para(t_point p, t_env *e)
{
	(void)e;
	(void)p;
}

void	calculate_conic(t_point p, t_env *e)
{
	(void)e;
	(void)p;
}
