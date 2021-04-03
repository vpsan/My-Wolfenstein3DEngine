#include "game.h"

int		sprts_casting(t_game *cube)
{
	int i;

	i = 0;
	while (i < cube->sprts.num_sprites)
	{
		cube->sprts.sprite_order[i] = i;
		cube->sprts.sprite_distance[i] =
				((cube->plr.pos_x - cube->sprts.pos_x[i])
				 * (cube->plr.pos_x - cube->sprts.pos_x[i]) +
				 (cube->plr.pos_y - cube->sprts.pos_y[i])
				 * (cube->plr.pos_y - cube->sprts.pos_y[i]));
		i++;
	}
//	sprts_sort(cube);
	return (0);
}

int		sprts(t_game *cube)
{
	sprts_casting(cube);
	return (0);
}
