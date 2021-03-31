#include "game.h"

int 	move_w(t_game *cube)
{
	double new_pos_x;
	double new_pos_y;

	new_pos_x = cube->plr.pos_x + cube->plr.dir_x * SPEED_MOVE;
	new_pos_y = cube->plr.pos_y + cube->plr.dir_y * SPEED_MOVE;
	if (cube->map[(int)new_pos_x][(int)cube->plr.pos_y] == '0')
		cube->plr.pos_x = new_pos_x;
	if (cube->map[(int)cube->plr.pos_x][(int)new_pos_y] == '0')
		cube->plr.pos_y = new_pos_y;
	return (0);
}

int 	move_s(t_game *cube)
{
	double new_pos_x;
	double new_pos_y;

	new_pos_x = cube->plr.pos_x - cube->plr.dir_x * SPEED_MOVE;
	new_pos_y = cube->plr.pos_y - cube->plr.dir_y * SPEED_MOVE;
	if (cube->map[(int)new_pos_x][(int)cube->plr.pos_y] == '0')
		cube->plr.pos_x = new_pos_x;
	if (cube->map[(int)cube->plr.pos_x][(int)new_pos_y] == '0')
		cube->plr.pos_y = new_pos_y;
	return (0);
}

int 	move_d(t_game *cube)
{
	double new_pos_x;
	double new_pos_y;

	new_pos_x = cube->plr.pos_x - cube->plr.dir_y * SPEED_MOVE;
	new_pos_y = cube->plr.pos_y + cube->plr.dir_x * SPEED_MOVE;
	if (cube->map[(int)new_pos_x][(int)cube->plr.pos_y] == '0')
		cube->plr.pos_x = new_pos_x;
	if (cube->map[(int)cube->plr.pos_x][(int)new_pos_y] == '0')
		cube->plr.pos_y = new_pos_y;
	return (0);
}

int 	move_a(t_game *cube)
{
	double new_pos_x;
	double new_pos_y;

	new_pos_x = cube->plr.pos_x + cube->plr.dir_y * SPEED_MOVE;
	new_pos_y = cube->plr.pos_y - cube->plr.dir_x * SPEED_MOVE;
	if (cube->map[(int)new_pos_x][(int)cube->plr.pos_y] == '0')
		cube->plr.pos_x = new_pos_x;
	if (cube->map[(int)cube->plr.pos_x][(int)new_pos_y] == '0')
		cube->plr.pos_y = new_pos_y;
	return (0);
}

int 	move_right(t_game *cube)
{
	double oldDirX;
	double oldPlaneX;

	oldDirX = cube->plr.dir_x;
	oldPlaneX = cube->plr.plane_x;
	cube->plr.dir_x = cube->plr.dir_x * cos(SPEED_TURN) - cube->plr.dir_y * sin(SPEED_TURN);
	cube->plr.dir_y = oldDirX * sin(SPEED_TURN) + cube->plr.dir_y * cos(SPEED_TURN);
	cube->plr.plane_x = cube->plr.plane_x * cos(SPEED_TURN) - cube->plr.plane_y * sin(SPEED_TURN);
	cube->plr.plane_y = oldPlaneX * sin(SPEED_TURN) + cube->plr.plane_y * cos(SPEED_TURN);
	return (0);
}

int 	move_left(t_game *cube)
{
	double oldDirX;
	double oldPlaneX;

	oldDirX = cube->plr.dir_x;
	oldPlaneX = cube->plr.plane_x;
	cube->plr.dir_x = cube->plr.dir_x * cos(-SPEED_TURN) - cube->plr.dir_y *
			sin(-SPEED_TURN);
	cube->plr.dir_y = oldDirX * sin(-SPEED_TURN) + cube->plr.dir_y * cos
			(-SPEED_TURN);
	cube->plr.plane_x = cube->plr.plane_x * cos(-SPEED_TURN) - cube->plr
			.plane_y * sin(-SPEED_TURN);
	cube->plr.plane_y = oldPlaneX * sin(-SPEED_TURN) + cube->plr.plane_y *
			cos(-SPEED_TURN);
	return (0);
}
