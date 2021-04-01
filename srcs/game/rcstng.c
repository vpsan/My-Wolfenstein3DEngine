#include "game.h"

int		rcstng_init_1(t_game *cube, int x_i)
{
	cube->rcstg.camera_x = 2 *(cube->map_prmtrs.win_width - x_i)
			/ (double)(cube->map_prmtrs.win_width) - 1;
	cube->rcstg.ray_dir_x =
			cube->plr.dir_x + cube->plr.plane_x * cube->rcstg.camera_x;
	cube->rcstg.ray_dir_y =
			cube->plr.dir_y + cube->plr.plane_y * cube->rcstg.camera_x;
	cube->rcstg.map_x = (int)cube->plr.pos_x;
	cube->rcstg.map_y = (int)cube->plr.pos_y;

	cube->rcstg.delta_dist_x = fabs(1/cube->rcstg.ray_dir_x);
	cube->rcstg.delta_dist_y = fabs((1/cube->rcstg.ray_dir_y));

	cube->rcstg.hit = 0;
	cube->rcstg.side = -1;
	return (0);
}

int 	rcstng_init_2(t_game *cube)
{
	if (cube->rcstg.ray_dir_x < 0)
	{
		cube->rcstg.step_x = -1;
		cube->rcstg.side_dist_x =
				(cube->plr.pos_x - cube->rcstg.map_x) * cube->rcstg.delta_dist_x;
	}
	else
	{
		cube->rcstg.step_x = 1;
		cube->rcstg.side_dist_x =
				(cube->rcstg.map_x + 1.0 - cube->plr.pos_x) * cube->rcstg.delta_dist_x;
	}
	if (cube->rcstg.ray_dir_y < 0)
	{
		cube->rcstg.step_y = -1;
		cube->rcstg.side_dist_y =
				(cube->plr.pos_y - cube->rcstg.map_y) * cube->rcstg.delta_dist_y;
	}
	else
	{
		cube->rcstg.step_y = 1;
		cube->rcstg.side_dist_y =
				(cube->rcstg.map_y + 1.0 - cube->plr.pos_y) * cube->rcstg.delta_dist_y;
	}
	return (0);
}

int 	rcstng_3(t_game *cube, int x)
{
	while (cube->rcstg.hit == 0)
	{
		//Jump to next map square, OR in x-direction, OR in y-direction
		if (cube->rcstg.side_dist_x < cube->rcstg.side_dist_y)
		{
			cube->rcstg.side_dist_x += cube->rcstg.delta_dist_x;
			cube->rcstg.map_x += cube->rcstg.step_x;
			cube->rcstg.side = 0;
		}
		else
		{
			cube->rcstg.side_dist_y += cube->rcstg.delta_dist_y;
			cube->rcstg.map_y += cube->rcstg.step_y;
			cube->rcstg.side = 1;
		}
		//Check if ray has hit a wall
		if (cube->map[cube->rcstg.map_x][cube->rcstg.map_y] > '0')
			cube->rcstg.hit = 1;
	}

	if (cube->rcstg.side == 0)
		cube->rcstg.perp_wall_dist = (cube->rcstg.map_x - cube->plr.pos_x + (1 -
				cube->rcstg.step_x) / 2) /
				cube->rcstg.ray_dir_x;
	else
		cube->rcstg.perp_wall_dist = (cube->rcstg.map_y - cube->plr.pos_y + (1 -
				cube->rcstg.step_y) / 2) / cube->rcstg.ray_dir_y;

	//Calculate height of line to draw on screen
	cube->rcstg.line_height = (int)(cube->map_prmtrs.win_height / cube->rcstg
			.perp_wall_dist);

	//Calculate lowest and highest pixel to fill in current stripe
	cube->rcstg.draw_start = -cube->rcstg.line_height / 2 + cube->map_prmtrs.win_height / 2;
	if(cube->rcstg.draw_start < 0)
		cube->rcstg.draw_start = 0;

	cube->rcstg.draw_end = cube->rcstg.line_height / 2 + cube->map_prmtrs.win_height / 2;
	if(cube->rcstg.draw_end >= cube->map_prmtrs.win_height)
		cube->rcstg.draw_end = cube->map_prmtrs.win_height - 1;

	if (cube->plr.pos_y > cube->rcstg.map_y && cube->rcstg.side)
		cube->rcstg.color = RED;
	else if (cube->plr.pos_y < cube->rcstg.map_y && cube->rcstg.side)
		cube->rcstg.color = BLUE;
	else if (cube->plr.pos_x > cube->rcstg.map_x && !cube->rcstg.side)
		cube->rcstg.color = WHITE;
	else if (cube->plr.pos_x < cube->rcstg.map_x && !cube->rcstg.side)
		cube->rcstg.color = GREEN;

	while (cube->rcstg.draw_start < cube->rcstg.draw_end)
	{
		color_pixel_fill(&cube->frame, x, cube->rcstg.draw_start,
						 cube->rcstg.color);
		cube->rcstg.draw_start++;
	}
	return (0);
}

int 	rcstng(t_game *cube)
{
	int		x;

	x = 0;
	while (x < cube->map_prmtrs.win_width)
	{
		rcstng_init_1(cube, x);
		rcstng_init_2(cube);
		rcstng_3(cube, x);
		x++;
	}
	return (0);
}
