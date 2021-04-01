#include "game.h"

int		turn_right(t_game *cube)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = cube->plr.dir_x;
	old_plane_x = cube->plr.plane_x;
	cube->plr.dir_x =
		cube->plr.dir_x * cos(SPEEDTRN) - cube->plr.dir_y * sin(SPEEDTRN);
	cube->plr.dir_y =
		old_dir_x * sin(SPEEDTRN) + cube->plr.dir_y * cos(SPEEDTRN);
	cube->plr.plane_x =
		cube->plr.plane_x * cos(SPEEDTRN) - cube->plr.plane_y * sin(SPEEDTRN);
	cube->plr.plane_y =
		old_plane_x * sin(SPEEDTRN) + cube->plr.plane_y * cos(SPEEDTRN);
	return (0);
}

int		turn_left(t_game *cube)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = cube->plr.dir_x;
	old_plane_x = cube->plr.plane_x;
	cube->plr.dir_x =
		cube->plr.dir_x * cos(-SPEEDTRN) - cube->plr.dir_y * sin(-SPEEDTRN);
	cube->plr.dir_y =
		old_dir_x * sin(-SPEEDTRN) + cube->plr.dir_y * cos(-SPEEDTRN);
	cube->plr.plane_x =
		cube->plr.plane_x * cos(-SPEEDTRN) - cube->plr.plane_y * sin(-SPEEDTRN);
	cube->plr.plane_y =
		old_plane_x * sin(-SPEEDTRN) + cube->plr.plane_y * cos(-SPEEDTRN);
	return (0);
}
