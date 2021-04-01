#include "game.h"

int		game_init(t_game *cube)
{
	game_window_init(cube);
	game_frame_init(cube);
	game_player_init(cube);
	game_keys_init(cube);
	game_textures_init(cube);
	game_raycasting_init(cube);
	return (0);
}
