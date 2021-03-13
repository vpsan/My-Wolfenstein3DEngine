#ifndef FILE_PARSER_H
# define FILE_PARSER_H

# include <stdlib.h>
# include <unistd.h>

int		file_main_parsing_function(char *argv_1, t_game* cube);
int     file_parse_file(int fd, t_game* cube);

#endif