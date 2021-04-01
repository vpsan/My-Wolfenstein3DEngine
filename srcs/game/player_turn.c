#include "game.h"

int		turn_right(t_game *cube)
{
	double oldDirX;
	double oldPlaneX;

	oldDirX = cube->plr.dir_x;
	oldPlaneX = cube->plr.plane_x;
	cube->plr.dir_x =
		cube->plr.dir_x * cos(SPEED_TURN) - cube->plr.dir_y * sin(SPEED_TURN);
	cube->plr.dir_y =
		oldDirX * sin(SPEED_TURN) + cube->plr.dir_y * cos(SPEED_TURN);
	cube->plr.plane_x =
		cube->plr.plane_x * cos(SPEED_TURN) - cube->plr.plane_y * sin(SPEED_TURN);
	cube->plr.plane_y =
		oldPlaneX * sin(SPEED_TURN) + cube->plr.plane_y * cos(SPEED_TURN);
	return (0);
}

int		turn_left(t_game *cube)
{
	double oldDirX;
	double oldPlaneX;

	oldDirX = cube->plr.dir_x;
	oldPlaneX = cube->plr.plane_x;
	cube->plr.dir_x =
		cube->plr.dir_x * cos(-SPEED_TURN) - cube->plr.dir_y * sin(-SPEED_TURN);
	cube->plr.dir_y =
		oldDirX * sin(-SPEED_TURN) + cube->plr.dir_y * cos(-SPEED_TURN);
	cube->plr.plane_x =
		cube->plr.plane_x * cos(-SPEED_TURN) - cube->plr.plane_y * sin(-SPEED_TURN);
	cube->plr.plane_y =
		oldPlaneX * sin(-SPEED_TURN) + cube->plr.plane_y * cos(-SPEED_TURN);
	return (0);
}
