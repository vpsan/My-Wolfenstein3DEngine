#ifndef	DEBUG_H
# define DEBUG_H

# include "libft.h"
# include "get_next_line.h"
# include "my_errors.h"
# include "file_parse.h"
# include "game.h"

# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>

int 	debug_print_check_map(t_game *cube);
void 	debug_fill_map_instead_parsing(t_game *cube);
char	*g_new_map[5];

#endif