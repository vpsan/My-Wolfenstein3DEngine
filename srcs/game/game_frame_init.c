#include "game.h"

int		game_frame_init(t_game *cube)
{
	cube->frame.img_ptr = mlx_new_image(cube->mlx_ptr,
										cube->map_prmtrs.win_width,
										cube->map_prmtrs.win_height);
	cube->frame.addr_ptr = mlx_get_data_addr(cube->frame.img_ptr,
										&cube->frame.bits_per_pixel,
										&cube->frame.size_line,
										&cube->frame.endian);
	return (0);
}
