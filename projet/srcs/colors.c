/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 19:21:00 by vchaillo          #+#    #+#             */
/*   Updated: 2015/02/14 23:32:12 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		select_french_color(int x)
{
	int		color;

	color = BLUE;
	if (x >= WIN_W / 3)
		color = WHITE;
	if (x >= (WIN_W / 3) * 2)
		color = RED;
	return (color);
}

int		select_blue_and_white(t_point p1, t_point p2)
{
	int	color;

	if (p1.z == p2.z)
	{
		if (p1.z == 0)
			color = BLUE;
		else
			color = WHITE;
	}
	else
		color = LIGHT_BLUE;
	return(color);
}
