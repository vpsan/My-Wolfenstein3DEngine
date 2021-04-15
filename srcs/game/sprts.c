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

int 	sprts_prmtrs_init(t_game *cube, int i)
{
	cube->sprts.sprite_x = cube->sprts.pos_x[cube->sprts.sprite_order[i]] -
			cube->plr.pos_x;
	cube->sprts.sprite_y = cube->sprts.pos_y[cube->sprts.sprite_order[i]] -
			cube->plr.pos_y;
	cube->sprts.inv_det = 1.0 /
			(cube->plr.plane_x * cube->plr.dir_y - cube->plr.dir_x *
			cube->plr.plane_y);
	cube->sprts.transform_x = cube->sprts.inv_det *
			(cube->plr.dir_y * cube->sprts.sprite_x -
				cube->plr.dir_x * cube->sprts.sprite_y);
	cube->sprts.transform_y = cube->sprts.inv_det *
			(-cube->plr.plane_y * cube->sprts.sprite_x +
				cube->plr.plane_x * cube->sprts.sprite_y);
	cube->sprts.sprite_screen_x = (int)(cube->map_prmtrs.win_width
			- cube->map_prmtrs.win_width / 2 *
				(1 + cube->sprts.transform_x / cube->sprts.transform_y));
	return (0);
}

int		sprts(t_game *cube)
{
	int i;

	sprts_casting(cube);
	i = 0;
	while (i < cube->sprts.num_sprites)
	{
		sprts_prmtrs_init(cube, i);
		i++;
	}
	return (0);
}
