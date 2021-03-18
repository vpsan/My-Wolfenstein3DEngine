#include "mlx.h"
#include "libft.h"
#include "game.h"
#include "my_errors.h"

int		game_map_init(t_game *cube)
{
	cube->map = NULL;
	cube->head_lstmap = NULL;
	return (0);
}

int 	game_window_init(t_game *cube)
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

int 	game_keys_init(t_game *cube)
{
	cube->keys.w = 0;
	cube->keys.a = 0;
	cube->keys.s = 0;
	cube->keys.d = 0;
	cube->keys.left = 0;
	cube->keys.right = 0;
	return (0);
}

//int 	game_textures_img_init(t_game *cube)
//{
//	printf("%p\n", cube->mlx_ptr);
//	printf("%s\n", cube->map_prmtrs.no_path);
//	printf("%d\n", cube->no_txtr.width);
//	printf("%d\n", cube->no_txtr.height);
//	cube->no_txtr.img_ptr = mlx_xpm_file_to_image(cube->mlx_ptr,
//											   &(cube->map_prmtrs.no_path),
//											   &(cube->no_txtr.width),
//											   &(cube->no_txtr.height));
//	cube->so_txtr.img_ptr = mlx_xpm_file_to_image(cube->mlx_ptr,
//											   &cube->map_prmtrs.so_path,
//											   &cube->so_txtr.width,
//											   &cube->so_txtr.height);
//	cube->we_txtr.img_ptr = mlx_xpm_file_to_image(cube->mlx_ptr,
//											   &cube->map_prmtrs.we_path,
//											   &cube->we_txtr.width,
//											   &cube->we_txtr.height);
//	cube->ea_txtr.img_ptr = mlx_xpm_file_to_image(cube->mlx_ptr,
//											   &cube->map_prmtrs.ea_path,
//											   &cube->ea_txtr.width,
//											   &cube->ea_txtr.height);
//	cube->sprts_txtr.img_ptr = mlx_xpm_file_to_image(cube->mlx_ptr,
//												  &cube->map_prmtrs.sprts_path,
//												  &cube->sprts_txtr.width,
//												  &cube->sprts_txtr.height);
//	return (0);
//}

//int 	game_textures_adr_init(t_game *cube)
//{
//	cube->no_txtr.addr_ptr = mlx_get_data_addr(cube->no_txtr.img_ptr,
//											   &cube->no_txtr.bpp,
//											   &cube->no_txtr.size_line,
//											   &cube->no_txtr.endian);
//	cube->so_txtr.addr_ptr = mlx_get_data_addr(cube->so_txtr.img_ptr,
//											   &cube->so_txtr.bpp,
//											   &cube->so_txtr.size_line,
//											   &cube->so_txtr.endian);
//	cube->we_txtr.addr_ptr = mlx_get_data_addr(cube->we_txtr.img_ptr,
//											   &cube->we_txtr.bpp,
//											   &cube->we_txtr.size_line,
//											   &cube->we_txtr.endian);
//	cube->ea_txtr.addr_ptr = mlx_get_data_addr(cube->ea_txtr.img_ptr,
//											   &cube->ea_txtr.bpp,
//											   &cube->ea_txtr.size_line,
//											   &cube->ea_txtr.endian);
//	cube->sprts_txtr.addr_ptr = mlx_get_data_addr(cube->sprts_txtr.img_ptr,
//											   &cube->sprts_txtr.bpp,
//											   &cube->sprts_txtr.size_line,
//											   &cube->sprts_txtr.endian);
//	return (0);
//}

int		game_init(t_game *cube)
{
	game_window_init(cube);
	//game_player_init();
//	game_keys_init(cube);
//	game_textures_img_init(cube);
//	game_textures_adr_init(cube);
	//game_raycasting_init();
	return (0);
}