#include "fdf.h"

void	draw_line_1(t_point p1, t_point p2, t_env *e)
{
	int	x;
	int	dx;
	int	dy;
	int	color;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	if (dx < 0)
	{
	//	draw_line_2(p2, p1, e);
		ft_putendl("busted!");
		x = p2.x;
		while (x <= p1.x)
		{
			color = select_color_mode(e->color_mode, x, p1.y);
			fill_pixel(e, color, x, p2.y + ((p1.y - p2.y) * (x - p2.x)) / (p1.x - p2.x));
			x++;
		}
	}
	else
	{
		x = p1.x;
		while (x <= p2.x)
		{
			color = select_color_mode(e->color_mode, x, p1.y);
			fill_pixel(e, color, x, p1.y + (dy * (x - p1.x)) / dx);
			x++;
		}
	}
}
/*
void	draw_line_2(t_point p1, t_point p2, t_env *e)
{
	int	x;
	int	dx;
	int	dy;
	int	color;

	x = p1.x;
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
		while (x <= p2.x)
		{
			color = select_color_mode(e->color_mode, x, p1.y);
			fill_pixel(e, color, x, p1.y + (dy * (x - p1.x)) / dx);
			x++;
		}
}*/
