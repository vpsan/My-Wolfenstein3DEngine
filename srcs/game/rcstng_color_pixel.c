#include "game.h"

void	color_pixel_fill(t_frame_prmts *frame, int x, int y, int color)
{
	char	*new_addr_ptr;

	new_addr_ptr = frame->addr_ptr +
			(y * frame->size_line + x * (frame->bits_per_pixel / 8));
	*(unsigned int*)new_addr_ptr = color;
}
