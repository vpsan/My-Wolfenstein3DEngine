#include "game.h"

int		game_keys_init(t_game *cube)
{
	cube->keys.w = 0;
	cube->keys.a = 0;
	cube->keys.s = 0;
	cube->keys.d = 0;
	cube->keys.left = 0;
	cube->keys.right = 0;
	return (0);
}
