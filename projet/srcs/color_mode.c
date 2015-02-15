/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 18:54:06 by vchaillo          #+#    #+#             */
/*   Updated: 2015/02/15 20:26:32 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	color_mode(int color_mode, int x, t_point p1, t_point p2)
{
	int	color;

	if (color_mode == STD)
		color = WHITE;
	if (color_mode == FRENCH)
		color = select_french_color(x);
	if (color_mode == WHITE_BLUE)
		color = select_blue_and_white(p1, p2);
	return (color);
}
