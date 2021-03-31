#include "debug.h"

int 	debug_map_prmtrs_init(t_game *cube)
{
	cube->map_prmtrs.win_width = 1020;
	cube->map_prmtrs.win_height = 960;
	//////////////////////////////////////////////////////////
	cube->map_prmtrs.no_path = "textures/marbface.xpm";
	cube->map_prmtrs.so_path = "textures/mountains.xpm";
	cube->map_prmtrs.we_path = "textures/metal.xpm";
	cube->map_prmtrs.ea_path = "textures/brick.xpm";
	cube->map_prmtrs.sprts_path = "textures/skeleton.xpm";

	cube->no_txtr.width = 64;
	cube->no_txtr.height = 64;

	cube->so_txtr.width = 64;
	cube->so_txtr.height = 64;

	cube->we_txtr.width = 64;
	cube->we_txtr.height = 64;

	cube->ea_txtr.width = 64;
	cube->ea_txtr.height = 64;

	cube->sprts_txtr.width = 64;
	cube->sprts_txtr.height = 64;
	///////////////////////////////////////////////////////
	cube->map_prmtrs.clr_flr = NAVI_clr_flr;
	cube->map_prmtrs.clr_clng = BLACK_clr_clng;
	return (0);
}