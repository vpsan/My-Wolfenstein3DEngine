#include "prsng_vldtn.h"
#include "my_errors.h"

int 	vldthn_resolution_prmtrs(t_game *cube)
{
	if (cube->map_prmtrs.win_height < MIN_WIN_HIEGHT ||
	cube->map_prmtrs.win_width < MIN_WIN_WIDTH ||
	cube->map_prmtrs.win_height > MAX_WIN_HIEGHT ||
	cube->map_prmtrs.win_width > MAX_WIN_WIDTH)
	{
		my_exit(2);
	}
	return (0);
}

int 	prsng_resolution(char **arr_split_line, t_game *cube)
{
	if (vldthn_count_arrsplitline(arr_split_line) != 3)
		my_exit(2);
//	if (arr_split_line[1,2] != '0123456789')
	cube->map_prmtrs.win_width = ft_atoi(arr_split_line[1]);
	cube->map_prmtrs.win_height = ft_atoi(arr_split_line[2]);
	vldthn_resolution_prmtrs(cube);
	return (0);
}
