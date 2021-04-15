#include "game.h"

int	set_sprites_num(t_game *cube)
{
	int		num_sprites;
	int		i;
	int		j;

	num_sprites = 0;
	i = 0;
	while (cube->map[i] != NULL)
	{
		j = 0;
		while (cube->map[i][j] != '\0')
		{
			if (cube->map[i][j] == '2')
			{
				num_sprites++;
			}
			j++;
		}
		i++;
	}
	if (num_sprites >= MAX_SPRTS_NUM)
		my_exit(15);
	return (num_sprites);
}

int	set_sprites_pos(t_game *cube)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	while (cube->map[i] != NULL)
	{
		j = 0;
		while (cube->map[i][j] != '\0')
		{
			if (cube->map[i][j] == '2')
			{
				cube->sprts.pos_x[k] = i + 0.5;
				cube->sprts.pos_y[k] = j + 0.5;
				k++;
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	game_sprites_init(t_game *cube)
{
	cube->sprts.num_sprites = set_sprites_num(cube);
	set_sprites_pos(cube);
	cube->sprts.sprite_x = -1.0;
	cube->sprts.sprite_y = -1.0;
	cube->sprts.inv_det = -1.0;
	cube->sprts.transform_x = -1.0;
	cube->sprts.transform_y = -1.0;
	cube->sprts.sprite_screen_x = -1;
	cube->sprts.sprite_height = -1;
	cube->sprts.sprite_width = -1;
	cube->sprts.draw_start_y = -1;
	cube->sprts.draw_end_y = -1;
	cube->sprts.draw_start_x = -1;
	cube->sprts.draw_end_x = -1;
	return (0);
}
