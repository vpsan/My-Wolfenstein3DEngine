#include "game.h"

int 	pre_rcstng_draw_ceiling(t_game *cube)
{
	int x;
	int y;

	y = 0;
	while (y < cube->map_prmtrs.win_height/2)
	{
		x = 0;
		while (x < cube->map_prmtrs.win_width)
		{
			rcstng_color_pixel(&cube->nxt_frame, x, y,
					  cube->map_prmtrs.clr_clng);
			x++;
		}
		y++;
	}
	return (0);
}

int 	pre_rcstng_draw_floor(t_game *cube)
{
	int x;
	int y;

	y = cube->map_prmtrs.win_height/2;
	while (y < cube->map_prmtrs.win_height)
	{
		x = 0;
		while (x < cube->map_prmtrs.win_width)
		{
			rcstng_color_pixel(&cube->nxt_frame, x, y,
							   cube->map_prmtrs.clr_flr);
			x++;
		}
		y++;
	}
	return (0);
}

int 	hook_next_frame(t_game *cube)
{
//	pre_rcstng_move_player(cube);
	pre_rcstng_draw_ceiling(cube);
	pre_rcstng_draw_floor(cube);
//	rcstng(cube);
	mlx_put_image_to_window(cube->mlx_ptr,
						 cube->win_ptr,
						 cube->nxt_frame.img_ptr,0, 0);
	return (0);
}