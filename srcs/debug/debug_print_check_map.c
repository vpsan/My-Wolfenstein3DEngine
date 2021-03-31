#include "debug.h"

int 	debug_print_check_map(t_game *cube)
{
	int i;

	i = 0;
	while (cube->map[i] != NULL)
	{
		printf("%s\n", cube->map[i]);
		i++;
	}
	return (0);
}
