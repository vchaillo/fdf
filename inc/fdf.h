/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 19:24:48 by vchaillo          #+#    #+#             */
/*   Updated: 2017/04/03 03:13:59 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft.h"
# include "structs.h"
# include "macros.h"
# include "colors.h"

void			start_mlx(char *path);
int				expose_hook(t_env *e);
int				key_hook(int keycode, t_env *e);
int				mouse_hook(int button, int x, int y, t_env *e);
t_point			**create_map(t_env *e);
t_point			*create_t_point_line(t_env *e, char *line, int y);
t_point			get_point_infos(t_env *e, char *str, int x, int y);
int				get_nb_map_lines(t_env *e);
int				get_tab_len(char **tab);
void			open_error(t_env *e);
void			malloc_error(void);
void			draw_menu(t_env *e);
void			draw_header(t_env *e);
void			draw_map(t_env *e);
void			draw_lines(t_point p1, t_point p2, t_env *e);
void			draw_line_1(t_point p1, t_point p2, t_env *e);
void			draw_line_2(t_point p1, t_point p2, t_env *e);
void			fill_pixel(t_env *e, int color, int x, int y);
void			fill_head_pixel(t_env *e, int color, int x, int y);
int				color_mode(int color_mode, int x, t_point p1, t_point p2);
int				select_standard_color(t_point p1, t_point p2);
int				select_french_color(int x);
int				select_mars_color(t_point p1, t_point p2);
int				select_earth_color(t_point p1, t_point p2);
void			calculate(t_env *e);
void			calculate_iso(t_point *p, t_env *e);
void			calculate_para(t_point *p, t_env *e);
void			calculate_conic(t_point *p, t_env *e);
void			erase_image(t_env *e);
void			vanilla_mode(t_env *e);
void			move_lr(t_env *e, int keycode);
void			move_ud(t_env *e, int keycode);
void			change_peaks(t_env *e, int keycode);
void			change_zoom(t_env *e, int keycode);
void			put_head_strings(t_env *e);
void			put_menu_strings(t_env *e);
void			put_strings_1(t_env *e);
void			put_strings_2(t_env *e);
void			move_key_hook(int keycode, t_env *e);
void			color_key_hook(int keycode, t_env *e);
void			projection_key_hook(int keycode, t_env *e);
void			rotation_key_hook(int keycode, t_env *e);
void			projection_mouse_hook(t_env *e, int x);
void			color_mouse_hook(t_env *e, int x);
void			rotation_mouse_hook(t_env *e, int x);
void			rotation_left(t_env *e);
void			rotation_right(t_env *e);

#endif
