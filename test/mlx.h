/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 17:19:23 by valentin          #+#    #+#             */
/*   Updated: 2014/12/15 19:32:13 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_H
# define MLX_H

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "get_next_line.h"

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	int	x_rect;
	char	*path;
	char	**map;
}		t_env;

int	load_window(void);


# define WIN_H 720
# define WIN_W 1280
# define RECT_H 50
# define RECT_W 30


# define GREEN 0x33CC00
# define LIGHT_BLUE 0x067EC4
# define DARK_BLUE 0x133F59
# define WHITE 0xFFFFFF
# define BLACK 0x000000

#endif
