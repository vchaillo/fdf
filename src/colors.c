/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 19:21:00 by vchaillo          #+#    #+#             */
/*   Updated: 2017/04/03 07:55:36 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		color_mode(int color_mode, int x, t_point p1, t_point p2)
{
	int	color;

	if (color_mode == STD)
		color = select_standard_color(p1, p2);
	else if (color_mode == FRENCH)
		color = select_french_color(x);
	else if (color_mode == MARS)
		color = select_mars_color(p1, p2);
	else
		color = select_earth_color(p1, p2);
	return (color);
}

int		select_standard_color(t_point p1, t_point p2)
{
	int	color;

	if (p1.z == p2.z)
	{
		if (p1.z == 0)
			color = DARK_GREY;
		else
			color = WHITE;
	}
	else
		color = ORANGE;
	return (color);
}

int		select_french_color(int x)
{
	int	color;

	color = BLUE;
	if (x >= WIN_W / 3)
		color = WHITE;
	if (x >= (WIN_W / 3) * 2)
		color = RED;
	return (color);
}

int		select_mars_color(t_point p1, t_point p2)
{
	int	color;

	if (p1.z == p2.z)
	{
		if (p1.z == 0)
			color = BLACK;
		else
			color = MARS_RED;
	}
	else
		color = MARS_ORANGE;
	return (color);
}

int		select_earth_color(t_point p1, t_point p2)
{
	int	color;

	if (p1.z == p2.z)
	{
		if (p1.z == 0)
			color = SEA_BLUE;
		else
			color = BROWN;
	}
	else
	{
		color = GRASS_GREEN;
	}
	return (color);
}
