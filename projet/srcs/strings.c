#include "fdf.h"

void	strings(t_env *e)
{
	mlx_string_put(e->mlx, e->win, TEXT_W, TEXT_H, WHITE, \
			"FDF by vchaillo");
	mlx_string_put(e->mlx, e->win, CASE_W * 9 + TEXT_W, TEXT_H, WHITE, \
			"RESET DISPLAY");
	mlx_string_put(e->mlx, e->win, CASE_W * 8 + TEXT_W, TEXT_H, WHITE, \
			"ISOMETRIC VIEW");
	mlx_string_put(e->mlx, e->win, CASE_W * 7 + TEXT_W, TEXT_H, WHITE, \
			"PARALLEL VIEW");
}
