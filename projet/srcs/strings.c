#include "fdf.h"

void	strings(t_env *e)
{
	white_strings(e);
	dark_strings(e);
}

void	white_strings(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 7, 30, WHITE, \
			"FDF by vchaillo, Project of 42");
	mlx_string_put(e->mlx, e->win, WIN_W - 140, 30, WHITE, \
			"RESET DISPLAY");
	mlx_string_put(e->mlx, e->win, WIN_W - 331, 30, WHITE, \
			"ISOMETRIC VIEW");
	mlx_string_put(e->mlx, e->win, WIN_W - 523, 30, WHITE, \
			"PARALLEL VIEW");
}

void	dark_strings(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 8, 31, DARK_GREY, \
			"FDF by vchaillo, Project of 42");
	mlx_string_put(e->mlx, e->win, WIN_W - 139, 31, DARK_GREY, \
			"RESET DISPLAY");
	mlx_string_put(e->mlx, e->win, WIN_W - 330, 31, DARK_GREY, \
			"ISOMETRIC VIEW");
	mlx_string_put(e->mlx, e->win, WIN_W - 522, 31, DARK_GREY, \
			"PARALLEL VIEW");
}

