#include "fdf.h"

int	select_color_mode(int color_mode, int x, int y)
{
	int	color;

	if (color_mode == 0)
		color = WHITE;
	if (color_mode == 1)
		color = select_french_color(x, y);
	return (color);
}
