/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 19:24:48 by vchaillo          #+#    #+#             */
/*   Updated: 2015/02/10 18:53:54 by vchaillo         ###   ########.fr       */
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

# define STD 0
# define FRENCH 1
# define STROBO 2

# define ISO 0
# define PARA 1
# define CONIC 2

# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define LIGHT_GREY 0x707070
# define DARK_GREY 0x303030
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define RED 0xFF0000
# define PINK 0xFF00FF
# define ORANGE 0xFF6600
# define BROWN 0x663300

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	int				x2d;
	int				y2d;
	int				color;
}					t_point;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				size;
	int				endian;
	int				bpp;
	char			*path;
	int				proj_mode;
	int				color_mode;
	char			*zoom;
	int				max_w;
	int				max_h;
	t_point			**map;
}					t_env;

void				start_mlx(char *path);
int					expose_hook(t_env *e);
int					key_hook(int keycode, t_env *e);
t_point				**create_map(t_env *e);
t_point				*create_t_point_tab(t_env *e, char *line, int y);
t_point				get_point_infos(char *str, int x, int y);
int					get_grid_len(t_env *e);
int					check_char(char *str);
int					get_tab_len(char **tab);
void				open_error(t_env *e);
void				malloc_error(void);
void				draw_map(t_env *e);
void				draw_lines(t_point p1, t_point p2, t_env *e);
void				draw_line_1(t_point p1, t_point p2, t_env *e);
void				draw_line_2(t_point p1, t_point p2, t_env *e);
void				fill_pixel(t_env *e, int color, int x, int y);
int					select_color_mode(int color_mode, int x, int y);
int					select_french_color(int x, int y);
void				calculate(t_point *p, t_env *e);
void				calculate_iso(t_point *p, t_env *e);
void				calculate_para(t_point *p, t_env *e);
void				calculate_conic(t_point *p, t_env *e);

#endif
