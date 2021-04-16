#include "game.h"

int		sprts(t_game *cube, double *zbuffer)
{
	int i;

	sprts_casting(cube);
	i = 0;
	while (i < cube->sprts.num_sprites)
	{
		sprts_prmtrs_init(cube, i);
		sprts_calculate(cube);
		sprts_stripe_calculate(cube, zbuffer);
		i++;
	}
	return (0);
}
