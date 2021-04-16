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
				< cube->sprts.sprite_distance[j])
			{
				temp = cube->sprts.sprite_distance[j - 1];
				cube->sprts.sprite_distance[j - 1] = cube->sprts.sprite_distance[j];
				cube->sprts.sprite_distance[j] = temp;
				temp = (double)cube->sprts.sprite_order[j - 1];
				cube->sprts.sprite_order[j - 1] = cube->sprts.sprite_order[j];
				cube->sprts.sprite_order[j] = (int)temp;
			}
			j--;
		}
		i++;
	}
	return (0);
}
