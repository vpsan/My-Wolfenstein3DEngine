#include "game.h"

void	rcstng_color_pixel(t_img_frame *nxt_frame, int x, int y, int color)
{
	char	*new_addr_ptr;

	new_addr_ptr = nxt_frame->addr_ptr + (y * nxt_frame->size_line + x *
			(nxt_frame->bits_per_pixel / 8));
	*(unsigned int*)new_addr_ptr = color;
}