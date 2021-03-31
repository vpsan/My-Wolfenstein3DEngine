#include "mlx.h"
#include "libft.h"
#include "game.h"
#include "my_errors.h"
#include "debug.h"

int		game_map_init(t_game *cube)
{
	cube->map = NULL;
	cube->head_lstmap = NULL;
	return (0);
}

int 	game_preparsing_init(t_game *cube)
{
	cube->map_prmtrs.win_width = 1020;//640;
	cube->map_prmtrs.win_height = 960;//480;
	//////////////////////////////////////////////////////////
	cube->map_prmtrs.no_path = "textures/marbface.xpm";
	cube->map_prmtrs.so_path = "textures/mountains.xpm";
	cube->map_prmtrs.we_path = "textures/metal.xpm";
	cube->map_prmtrs.ea_path = "textures/brick.xpm";
	cube->map_prmtrs.sprts_path = "textures/skeleton.xpm";

	cube->no_txtr.width = 64;
	cube->no_txtr.height = 64;

	cube->so_txtr.width = 64;
	cube->so_txtr.height = 64;

	cube->we_txtr.width = 64;
	cube->we_txtr.height = 64;

	cube->ea_txtr.width = 64;
	cube->ea_txtr.height = 64;

	cube->sprts_txtr.width = 64;
	cube->sprts_txtr.height = 64;
	///////////////////////////////////////////////////////
	cube->map_prmtrs.clr_flr = 70;
	cube->map_prmtrs.clr_clng = BLACK;
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

int 	game_frame_init(t_game *cube)
{
	cube->nxt_frame.img_ptr = mlx_new_image(cube->mlx_ptr,
										 cube->map_prmtrs.win_width,
										 cube->map_prmtrs.win_height);
	cube->nxt_frame.addr_ptr = mlx_get_data_addr(cube->nxt_frame.img_ptr,
										&cube->nxt_frame.bits_per_pixel,
										&cube->nxt_frame.size_line,
										&cube->nxt_frame.endian);
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

int 	game_textures_img_init(t_game *cube)
{
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
//	check ptrs == NULL
	return (0);
}

int 	game_textures_adr_init(t_game *cube)
{
//	cube->no_txtr.addr_ptr = mlx_get_data_addr(cube->no_txtr.img_ptr,
//											   &cube->no_txtr.bits_per_pixel,
//											   &cube->no_txtr.size_line,
//											   &cube->no_txtr.endian);
//	cube->so_txtr.addr_ptr = mlx_get_data_addr(cube->so_txtr.img_ptr,
//											   &cube->so_txtr.bits_per_pixel,
//											   &cube->so_txtr.size_line,
//											   &cube->so_txtr.endian);
//	cube->we_txtr.addr_ptr = mlx_get_data_addr(cube->we_txtr.img_ptr,
//											   &cube->we_txtr.bits_per_pixel,
//											   &cube->we_txtr.size_line,
//											   &cube->we_txtr.endian);
//	cube->ea_txtr.addr_ptr = mlx_get_data_addr(cube->ea_txtr.img_ptr,
//											   &cube->ea_txtr.bits_per_pixel,
//											   &cube->ea_txtr.size_line,
//											   &cube->ea_txtr.endian);
//	cube->sprts_txtr.addr_ptr = mlx_get_data_addr(cube->sprts_txtr.img_ptr,
//											   &cube->sprts_txtr.bits_per_pixel,
//											   &cube->sprts_txtr.size_line,
//											   &cube->sprts_txtr.endian);
//	check ptrs == NULL
	return (0);
}

int		set_player_dir(t_game *cube, char plr_dir)
{
	if (plr_dir == 'N')
	{
		cube->plr.dir_x = 0;
		cube->plr.dir_y = -1;
		cube->plr.plane_x = -0.66;
		cube->plr.plane_y = 0;
	}
	if (plr_dir == 'S')
	{
		cube->plr.dir_x = 0;
		cube->plr.dir_y = 1;
		cube->plr.plane_x = 0.66;
		cube->plr.plane_y = 0;
	}
	if (plr_dir == 'E')
	{
		cube->plr.dir_x = 1;
		cube->plr.dir_y = 0;
		cube->plr.plane_x = 0;
		cube->plr.plane_y = -0.66;
	}
	if (plr_dir == 'W')
	{
		cube->plr.dir_x = -1;
		cube->plr.dir_y = 0;
		cube->plr.plane_x = 0;
		cube->plr.plane_y = 0.66;
	}
	return (0);
}

int 	game_player_init(t_game *cube)
{
	int 	i;
	int 	j;

	i = 0;
	while (cube->map[i] != NULL)
	{
		j = 0;
		while (cube->map[i][j] != '\0')
		{
			if (cube->map[i][j] == 'N' || cube->map[i][j] == 'S' ||
				cube->map[i][j] == 'E' || cube->map[i][j] == 'W')
			{
				cube->plr.pos_x = i;
				cube->plr.pos_y = j;
				set_player_dir(cube, cube->map[i][j]);
				cube->map[i][j] = '0';
				return (0);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int 	game_raycasting_init(t_game *cube)
{
	cube->rcstg.camera_x = 0;
	cube->rcstg.ray_dir_x = 0;
	cube->rcstg.ray_dir_y = 0;
	cube->rcstg.map_x = 0;
	cube->rcstg.map_y = 0;
	cube->rcstg.side_dist_x = 0;
	cube->rcstg.side_dist_y = 0;
	cube->rcstg.delta_dist_x = 0;
	cube->rcstg.delta_dist_y = 0;
	cube->rcstg.perp_wall_dist = 0;
	cube->rcstg.step_x = 0;
	cube->rcstg.step_y = 0;
	cube->rcstg.hit = 0;
	cube->rcstg.side = 0;
	cube->rcstg.side = 0;
	cube->rcstg.line_height = 0;
	cube->rcstg.draw_start = 0;
	cube->rcstg.draw_end = 0;
	return (0);
}

int		game_init(t_game *cube)
{
	game_window_init(cube);
	game_frame_init(cube);
	game_player_init(cube);
	game_keys_init(cube);
	game_textures_img_init(cube);
	game_textures_adr_init(cube);
	game_raycasting_init(cube);
	return (0);
}