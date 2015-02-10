/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 19:21:00 by vchaillo          #+#    #+#             */
/*   Updated: 2015/02/10 18:22:16 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		select_french_color(int x, int y)
{
	int		color;

	(void)y;
	color = BLUE;
	if (x >= WIN_W / 3)
		color = WHITE;
	if (x >= (WIN_W / 3) * 2)
		color = RED;
	return (color);
}
