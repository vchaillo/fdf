#include "fdf.h"

void	projection_mouse_hook(t_env *e, int x)
{
	if (x < CASE_W * 8)
		e->proj_mode = PARA;
	if (x > CASE_W * 8)
		e->proj_mode = ISO;
		
}

void	color_mouse_hook(t_env *e, int x)
{
	if (x < CASE_W * 2)
		e->color_mode = FRENCH;
	else if (x < CASE_W * 3)
		e->color_mode = MARS;
	else if (x < CASE_W * 4)
		e->color_mode = EARTH;
	else if (x < CASE_W * 5)
		e->color_mode = STD;
}

void	rotation_mouse_hook(t_env *e, int x)
{
	(void)e;
	(void)x;
}