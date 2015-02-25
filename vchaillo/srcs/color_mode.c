/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 18:54:06 by vchaillo          #+#    #+#             */
/*   Updated: 2015/02/17 06:02:36 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	color_mode(int color_mode, int x, t_point p1, t_point p2)
{
	int	color;

	if (color_mode == STD)
		color = select_standard_color(p1, p2);
	if (color_mode == FRENCH)
		color = select_french_color(x);
	if (color_mode == MARS)
		color = select_mars_color(p1, p2);
	if (color_mode == EARTH)
		color = select_earth_color(p1, p2);
	return (color);
}