#include "game.h"

int 	rcstng_init_2(t_game *cube)
{

	return (0);
}

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
	return (0);
}

int 	rcstng(t_game *cube)
{
	int		x;
	double	buf[cube->map_prmtrs.win_width];

	x = 0;
	while (x < cube->map_prmtrs.win_width)
	{
		rcstng_init_1(cube, x);
		rcstng_init_2(cube);
		x++;
	}
	return (0);
}