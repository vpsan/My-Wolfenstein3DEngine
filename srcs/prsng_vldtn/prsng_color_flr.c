# include "prsng_vldtn.h"

int		vldthn_color_flr_digits(char **arr_split_line, int exit_number)
{
	vldthn_chech_str_is_digits(arr_split_line[0], exit_number);
	vldthn_chech_str_is_digits(arr_split_line[1], exit_number);
	vldthn_chech_str_is_digits(arr_split_line[2], exit_number);
	return (0);
}

int     vldthn1_make_rgb(int *cube_map_prmtrs_color, int r, int g, int b)
{
	int result_rgb_color;

	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		my_exit(9);
	result_rgb_color = (r << 16 | g << 8 | b);
	*cube_map_prmtrs_color = result_rgb_color;
	return (0);
}

int 	prsng_color_flr(char **arr_split_line, t_game *cube)
{
	int		red;
	int 	green;
	int 	blue;
	char	**color_arr;

	if (vldthn_count_arrsplitline(arr_split_line) != 2)
		my_exit(9);
	color_arr = ft_split(arr_split_line[1], ',');
	if (vldthn_count_arrsplitline(color_arr) != 3)
		my_exit(9);
	vldthn_color_flr_digits(color_arr, 9);
	red = ft_atoi(color_arr[0]);
	green = ft_atoi(color_arr[1]);
	blue = ft_atoi(color_arr[2]);
	vldthn1_make_rgb(&cube->map_prmtrs.clr_flr, red, green, blue);
	ft_free_str_arr(&color_arr);
	return (0);
}
