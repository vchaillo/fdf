/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 18:54:06 by vchaillo          #+#    #+#             */
/*   Updated: 2015/02/05 19:34:19 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	select_color_mode(int color_mode, int x, int y)
{
	int	color;

	if (color_mode == STD)
		color = WHITE;
	if (color_mode == FRENCH)
		color = select_french_color(x, y);
	return (color);
}
