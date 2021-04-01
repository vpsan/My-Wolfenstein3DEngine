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
			color_pixel_fill(&cube->frame, x, y,
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
			color_pixel_fill(&cube->frame, x, y,
							 cube->map_prmtrs.clr_flr);
			x++;
		}
		y++;
	}
	return (0);
}

int 	pre_rcstng_move_player(t_game *cube)
{
	if (cube->keys.w == 1)
		move_w(cube);
	if (cube->keys.s == 1)
		move_s(cube);
	if (cube->keys.d == 1)
		move_d(cube);
	if (cube->keys.a == 1)
		move_a(cube);
	if (cube->keys.right == 1)
		move_right(cube);
	if (cube->keys.left == 1)
		move_left(cube);
	return (0);
}

void	loop_hook_next_frame(t_game *cube)
{
	pre_rcstng_move_player(cube);
	pre_rcstng_draw_ceiling(cube);
	pre_rcstng_draw_floor(cube);
	rcstng(cube);
	mlx_put_image_to_window(cube->mlx_ptr, cube->win_ptr,
							cube->frame.img_ptr, 0, 0);
	return ;
}