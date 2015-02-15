/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 18:29:38 by vchaillo          #+#    #+#             */
/*   Updated: 2015/02/15 20:07:36 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_strings(t_env *e)
{
	mlx_string_put(e->mlx, e->win, TEXT_W, TEXT_H, WHITE, \
			"FDF by vchaillo");
	mlx_string_put(e->mlx, e->win, (CASE_W) * 7 + TEXT_W, TEXT_H, WHITE, \
			"PARALLEL VIEW");
	mlx_string_put(e->mlx, e->win, (CASE_W * 8) + TEXT_W, TEXT_H, WHITE, \
			"ISOMETRIC VIEW");
	mlx_string_put(e->mlx, e->win, (CASE_W * 9) + TEXT_W, TEXT_H, WHITE, \
			"RESET DISPLAY");
}
