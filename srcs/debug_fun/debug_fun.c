#include "debug_fun.h"

int 	debug_print_check_map(char **map)
{
	int i;

	i = 0;
	while (map[i] != NULL)
	{
		printf("%s\n", map[i]);
		i++;
	}
	return (0);
}
