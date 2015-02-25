/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 08:20:13 by vchaillo          #+#    #+#             */
/*   Updated: 2015/02/18 02:28:59 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_lr(t_env *e, int keycode)
{
	if (keycode == 65361)
		e->move_lr += 50;
	else if (keycode == 65363)
		e->move_lr -= 50;
	e->menu = OFF;
}

void	move_ud(t_env *e, int keycode)
{
	if (keycode == 65364)
		e->move_ud -= 50;
	else if (keycode == 65362)
		e->move_ud += 50;
	e->menu = OFF;
}

void	change_peaks(t_env *e, int keycode)
{
	if (keycode == 65451)
		e->peaks += 5;
	else if (keycode == 65453)
		e->peaks -= 5;
	e->menu = OFF;
}

void	change_zoom(t_env *e, int keycode)
{
	if (keycode == 61)
		e->zoom += 3;
	else if (keycode == 45)
		e->zoom -= 3;
	e->menu = OFF;
}