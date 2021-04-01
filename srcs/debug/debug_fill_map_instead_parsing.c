#include "debug.h"

void	debug_fill_map_instead_parsing(t_game *cube)
{
	g_new_map[0] = "11111\0";
	g_new_map[1] = "1N001\0";
	g_new_map[2] = "10001\0";
	g_new_map[3] = "11111\0";
	g_new_map[4] = NULL;
	cube->map = g_new_map;
	return ;
}
