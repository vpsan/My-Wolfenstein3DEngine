#include "game.h"
#include "mlx.h"

int		game_map_init(t_game *cube)
{
	cube->map = NULL;
	cube->head_lstmap = NULL;
	return (0);
}

//int 	game_window_init(t_game *cube)
//{
//	if ((cube->mlx = mlx_init())== NULL)
//	{
//		ft_free_str_arr(cube->map);
//		//my_exit(1);
//	}
//	return (0);
//}

int		game_init(t_game *cube)
{
	//game_window_init();
	//game_player_init();
	//game_keys_init();
	//game_textures_init()
	//...
	//game_sprites_init();
	//game_raycasting_init();
	return (0);
}