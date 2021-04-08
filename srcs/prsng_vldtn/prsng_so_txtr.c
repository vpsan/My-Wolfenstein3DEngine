# include "prsng_vldtn.h"

int 	prsng_so_txtr(char **arr_split_line, t_game *cube)
{
	if (vldthn_count_arrsplitline(arr_split_line) != 2)
		my_exit(5);
	cube->map_prmtrs.so_path = ft_strdup(arr_split_line[1]);
	return (0);
}

