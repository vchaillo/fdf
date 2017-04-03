/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 15:11:35 by vchaillo          #+#    #+#             */
/*   Updated: 2017/04/03 08:17:00 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_key_hook(int keycode, t_env *e)
{
	if (keycode == 65361 || keycode == 65363)
		move_lr(e, keycode);
	else if (keycode == 65364 || keycode == 65362)
		move_ud(e, keycode);
	else if (keycode == 65451 || keycode == 65453)
		change_peaks(e, keycode);
	else if (keycode == 61 || keycode == 45)
		change_zoom(e, keycode);
}

void	color_key_hook(int keycode, t_env *e)
{
	if (keycode == 48 || keycode == 224)
		e->color_mode = STD;
	else if (keycode == 49 || keycode == 38)
		e->color_mode = FRENCH;
	else if (keycode == 50 || keycode == 233)
		e->color_mode = MARS;
	else if (keycode == 51 || keycode == 34)
		e->color_mode = EARTH;
}

void	projection_key_hook(int keycode, t_env *e)
{
	if (keycode == 65457 || keycode == 65436)
		e->proj_mode = ISO;
	else if (keycode == 65458 || keycode == 65433)
		e->proj_mode = PARA;
}

void	rotation_key_hook(int keycode, t_env *e)
{
	(void)keycode;
	(void)e;
}
