#include "game.h"

int		game_window_init(t_game *cube)
{
	if ((cube->mlx_ptr = mlx_init()) == NULL)
	{
		ft_free_str_arr(&cube->map);
		my_errors_call(3);
		exit(1);
	}
	if ((cube->win_ptr = mlx_new_window(cube->mlx_ptr,
										cube->map_prmtrs.win_width,
										cube->map_prmtrs.win_height,
										"Cub3D")) == NULL)
	{
		ft_free_str_arr(&cube->map);
		free(cube->mlx_ptr);
		my_errors_call(3);
		exit(1);
	}
	return (0);
}