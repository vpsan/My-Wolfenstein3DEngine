#include "game.h"

int		game_map_prmtrs_init(t_game *cube)
{
	cube->map_prmtrs.win_width = 0;
	cube->map_prmtrs.win_height = 0;
	cube->map_prmtrs.no_path = NULL;
	cube->map_prmtrs.so_path = NULL;
	cube->map_prmtrs.we_path = NULL;
	cube->map_prmtrs.ea_path = NULL;
	cube->map_prmtrs.clr_flr = 0;
	cube->map_prmtrs.clr_clng = 0;
	cube->map_prmtrs.sprts_path = NULL;
}
