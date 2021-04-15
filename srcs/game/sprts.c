#include "game.h"

int 	sprts_bubble_sort(t_game *cube)
{
	double temp;
	int i;
	int j;

	i = 0;
	while (i < cube->sprts.num_sprites - 1)
	{
		j = cube->sprts.num_sprites - 1;
		while (j > i)
		{
			if (cube->sprts.sprite_distance[j - 1]
				> cube->sprts.sprite_distance[j])
			{
				temp = cube->sprts.sprite_distance[j - 1];
				cube->sprts.sprite_distance[j - 1] = cube->sprts.sprite_distance[j];
				cube->sprts.sprite_distance[j] = temp;
				temp = cube->sprts.sprite_order[j - 1];
				cube->sprts.sprite_order[j - 1] = cube->sprts.sprite_order[j];
				cube->sprts.sprite_order[j] = temp;
			}
			j--;
		}
		i++;
	}
	return (0);
}

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
	sprts_bubble_sort(cube);
	return (0);
}

int		sprts(t_game *cube)
{
	sprts_casting(cube);
	return (0);
}
