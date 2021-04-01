#include "game.h"

int		rcstng_while_hit_not_zero(t_game *cube)
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
	return (0);
}

int 	rcstng_calculations(t_game *cube)
{
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
}

int		rcstng_calculate_wallx(t_game *cube)
{
	if (cube->rcstg.side == 0)
		cube->rcstg.wall_x = cube->plr.pos_y + cube->rcstg.perp_wall_dist *
											   cube->rcstg.ray_dir_y;
	else
		cube->rcstg.wall_x = cube->plr.pos_x + cube->rcstg.perp_wall_dist *
											   cube->rcstg.ray_dir_x;
	cube->rcstg.wall_x = 1 - (cube->rcstg.wall_x - floor(cube->rcstg.wall_x));

	cube->rcstg.tex_x = (int)(cube->rcstg.wall_x * cube->rcstg.tex->width);
	if (cube->rcstg.side == 0 && cube->rcstg.ray_dir_x > 0)
		cube->rcstg.tex_x = cube->rcstg.tex->width - cube->rcstg.tex_x - 1;
	if (cube->rcstg.side == 1 && cube->rcstg.ray_dir_y < 0)
		cube->rcstg.tex_x = cube->rcstg.tex->width - cube->rcstg.tex_x - 1;
	cube->rcstg.tex_step = (double)(cube->rcstg.tex->height) / cube->rcstg.line_height;
	cube->rcstg.tex_pos = (cube->rcstg.draw_start -
						   cube->map_prmtrs.win_height / 2 + cube->rcstg.line_height / 2) * cube->rcstg.tex_step;
	return (0);
}

int     rcstng_draw_wall(t_game *cube, int x)
{
	int		y;
	int		pixel_color;

	y = cube->rcstg.draw_start;
	while(y < cube->rcstg.draw_end)
	{
		cube->rcstg.tex_y = (int)(cube->rcstg.tex_pos) & (cube->rcstg.tex
																  ->height - 1);
		cube->rcstg.tex_pos += cube->rcstg.tex_step;
		pixel_color = ((int*)cube->rcstg.tex->addr_ptr)
		[cube->rcstg.tex_y * cube->rcstg.tex->width + cube->rcstg.tex_x];
		if (cube->rcstg.side == 1)
			pixel_color = (pixel_color >> 1) & 0x7F7F7F;
		color_pixel_fill(&cube->frame, x, y, pixel_color);
		y++;
	}
}

int 	rcstng_get_wall_tex(t_game *cube)
{
	if (cube->rcstg.side == 1)
	{
		if (cube->rcstg.step_y > 0)
			cube->rcstg.tex = &cube->no_txtr;
		if (cube->rcstg.step_y < 0)
			cube->rcstg.tex = &cube->so_txtr;
	}
	if (cube->rcstg.side == 0)
	{
		if (cube->rcstg.step_x > 0)
			cube->rcstg.tex = &cube->we_txtr;
		if (cube->rcstg.step_x < 0)
			cube->rcstg.tex = &cube->ea_txtr;
	}
	return (0);
}

int 	rcstng_without_textures(t_game *cube, int x)
{
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
		rcstng_while_hit_not_zero(cube);
		rcstng_calculations(cube);
		rcstng_calculate_wallx(cube);
		rcstng_get_wall_tex(cube);
		rcstng_draw_wall(cube, x);
//		rcstng_without_textures(cube, x);
		x++;
	}
	return (0);
}
