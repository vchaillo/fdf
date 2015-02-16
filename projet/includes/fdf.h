/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 19:24:48 by vchaillo          #+#    #+#             */
/*   Updated: 2015/02/16 03:39:27 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "../libft/includes/libft.h"

# define WIN_W 1920
# define WIN_H 1080
# define HEAD_H (WIN_H / 20)
# define IMG_H (WIN_H - HEAD_H)

# define CASE_H (WIN_H / 20)
# define CASE_W (WIN_W / 10)
# define TEXT_H (CASE_H / 8) * 5
# define TEXT_W (CASE_W / 10) * 3

# define STD 0
# define FRENCH 1
# define WHITE_BLUE 2
# define EARTH 3

# define ISO 0
# define PARA 1
# define CONIC 2

# define OFF 0
# define ON 1

# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define LIGHT_GREY 0x707070
# define DARK_GREY 0x303030
# define GREEN 0x00FF00
# define GRASS_GREEN 0x669933
# define BLUE 0x0000FF
# define SEA_BLUE 0x0066FF
# define LIGHT_BLUE 0x00CCFF
# define YELLOW 0xFFFF00
# define RED 0xFF0000
# define PINK 0xFF00FF
# define ORANGE 0xFF6600
# define BROWN 0x663300

typedef struct			s_point
{
	int			x;
	int			y;
	int			z;
	int			x2d;
	int			y2d;
	int			color;
}				t_point;

typedef struct			s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	void			*img_head;
	char			*data;
	char			*data_head;
	int			size;
	int			size_head;
	int			endian;
	int			bpp;
	char			*path;
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
	t_point			**map;
}				t_env;

void				start_mlx(char *path);
int				expose_hook(t_env *e);
int				key_hook(int keycode, t_env *e);
int				mouse_hook(int button, int x, int y, t_env *e);
t_point				**create_map(t_env *e);
t_point				*create_t_point_tab(t_env *e, char *line, int y);
t_point				get_point_infos(t_env *e, char *str, int x, int y);
int				get_grid_len(t_env *e);
int				check_char(char *str);
int				get_tab_len(char **tab);
void				open_error(t_env *e);
void				malloc_error(void);
void				draw_menu(t_env *e);
void				draw_header(t_env *e);
void				draw_map(t_env *e);
void				draw_lines(t_point p1, t_point p2, t_env *e);
void				draw_line_1(t_point p1, t_point p2, t_env *e);
void				draw_line_2(t_point p1, t_point p2, t_env *e);
void				fill_pixel(t_env *e, int color, int x, int y);
void				fill_head_pixel(t_env *e, int color, int x, int y);
int				color_mode(int color_mode, int x, t_point p1, t_point p2);
int				select_french_color(int x);
int				select_blue_and_white(t_point p1, t_point p2);
int				select_earth_color(t_point p1, t_point p2);
void				calculate(t_env *e);
void				calculate_iso(t_point *p, t_env *e);
void				calculate_para(t_point *p, t_env *e);
void				calculate_conic(t_point *p, t_env *e);
void				erase_image(t_env *e);
void				vanilla_mode(t_env *e);
void				move_lr(t_env *e, int keycode);
void				move_ud(t_env *e, int keycode);
void				change_peaks(t_env *e, int keycode);
void				change_zoom(t_env *e, int keycode);
void				put_head_strings(t_env *e);
void				put_menu_strings(t_env *e);

#endif
