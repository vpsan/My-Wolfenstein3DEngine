#include "game.h"

int		move_w(t_game *cube)
{
	double new_pos_x;
	double new_pos_y;

	new_pos_x = cube->plr.pos_x + cube->plr.dir_x * SPEEDMOVE;
	new_pos_y = cube->plr.pos_y + cube->plr.dir_y * SPEEDMOVE;
	if (cube->map[(int)new_pos_x][(int)cube->plr.pos_y] == '0')
		cube->plr.pos_x = new_pos_x;
	if (cube->map[(int)cube->plr.pos_x][(int)new_pos_y] == '0')
		cube->plr.pos_y = new_pos_y;
	return (0);
}

int		move_s(t_game *cube)
{
	double new_pos_x;
	double new_pos_y;

	new_pos_x = cube->plr.pos_x - cube->plr.dir_x * SPEEDMOVE;
	new_pos_y = cube->plr.pos_y - cube->plr.dir_y * SPEEDMOVE;
	if (cube->map[(int)new_pos_x][(int)cube->plr.pos_y] == '0')
		cube->plr.pos_x = new_pos_x;
	if (cube->map[(int)cube->plr.pos_x][(int)new_pos_y] == '0')
		cube->plr.pos_y = new_pos_y;
	return (0);
}

int		move_d(t_game *cube)
{
	double new_pos_x;
	double new_pos_y;

	new_pos_x = cube->plr.pos_x - cube->plr.dir_y * SPEEDMOVE;
	new_pos_y = cube->plr.pos_y + cube->plr.dir_x * SPEEDMOVE;
	if (cube->map[(int)new_pos_x][(int)cube->plr.pos_y] == '0')
		cube->plr.pos_x = new_pos_x;
	if (cube->map[(int)cube->plr.pos_x][(int)new_pos_y] == '0')
		cube->plr.pos_y = new_pos_y;
	return (0);
}

int		move_a(t_game *cube)
{
	double new_pos_x;
	double new_pos_y;

	new_pos_x = cube->plr.pos_x + cube->plr.dir_y * SPEEDMOVE;
	new_pos_y = cube->plr.pos_y - cube->plr.dir_x * SPEEDMOVE;
	if (cube->map[(int)new_pos_x][(int)cube->plr.pos_y] == '0')
		cube->plr.pos_x = new_pos_x;
	if (cube->map[(int)cube->plr.pos_x][(int)new_pos_y] == '0')
		cube->plr.pos_y = new_pos_y;
	return (0);
}