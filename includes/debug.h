#ifndef	DEBUG_H
# define DEBUG_H

# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include "libft.h"
# include "get_next_line.h"
# include "my_errors.h"
# include "prsng_vldtn.h"
# include "game.h"

int 	debug_print_check_map(t_game *cube);
void 	debug_fill_map_instead_parsing(t_game *cube);
int		debug_map_prmtrs_init(t_game *cube);
char	*g_new_map[5];

#endif