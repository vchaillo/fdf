/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 15:12:44 by vchaillo          #+#    #+#             */
/*   Updated: 2017/04/03 08:16:04 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	projection_mouse_hook(t_env *e, int x)
{
	if (x < CASE_W * 8)
		e->proj_mode = PARA;
	else if (x > CASE_W * 8)
		e->proj_mode = ISO;
}

void	color_mouse_hook(t_env *e, int x)
{
	if (x < CASE_W * 2)
		e->color_mode = FRENCH;
	else if (x < CASE_W * 3)
		e->color_mode = MARS;
	else if (x < CASE_W * 4)
		e->color_mode = EARTH;
	else if (x < CASE_W * 5)
		e->color_mode = STD;
}

void	rotation_mouse_hook(t_env *e, int x)
{
	if (x < CASE_W * 6)
		rotation_left(e);
	else if (x < CASE_W * 7)
		rotation_right(e);
}
