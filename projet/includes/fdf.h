/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 19:24:48 by vchaillo          #+#    #+#             */
/*   Updated: 2015/01/30 17:26:07 by vchaillo         ###   ########.fr       */
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

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_point;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			size;
	int			endian;
	int			bpp;
	char		*path;
	t_point		**map;
}				t_env;

int				start_mlx(char *path);
t_point			**create_map(t_env *e);
int				get_grid_len(t_env *e);
int				check_char(char *str);
t_point			*create_t_point_tab(char *line, int y);
int				get_tab_len(char **tab);
t_point			get_point_infos(char *str, int x, int y);
int				expose_hook(t_env *e);
int				key_hook(int keycode, t_env *e);
void			open_error(t_env *e);
void			malloc_error(void);
int				draw_map(t_env *e);
int				draw_line(t_point p1, t_point p2, t_env *e);
int				draw_france_flag(t_env *e);
void			put_color_on_pixel(t_env *e, int color, int x, int y);
int				select_a_color(int x, int y);
void			draw_line_img(t_point p1, t_point p2, t_env *e);

# define WIN_H 720
# define WIN_W 1280

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

#endif
