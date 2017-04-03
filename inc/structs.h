/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 02:38:31 by valentin          #+#    #+#             */
/*   Updated: 2017/04/03 02:39:43 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
	int			x2d;
	int			y2d;
	int			color;
}				t_point;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*img_head;
	char		*data;
	char		*data_head;
	int			size;
	int			size_head;
	int			endian;
	int			bpp;
	char		*path;
	int			zoom;
	int			move_ud;
	int			move_lr;
	int			peaks;
	int			proj_mode;
	int			color_mode;
	int			max_w;
	int			max_h;
	int			max_z;
	int			menu;
	int			calcul;
	int			rotation;
	t_point		**map;
}				t_env;

#endif
