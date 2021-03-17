#include "libft.h"
#include "get_next_line.h"
#include "game.h"
#include <stdio.h>

#include <stdbool.h>
#include <fcntl.h>

int 	file_creat_map(t_game **cube)
{
	int		i;
	t_list	*tmp;

	(*cube)->map = ft_calloc(ft_lstsize((*cube)->head_lstmap) + 1, sizeof(char *));
	i = -1;
	tmp = (*cube)->head_lstmap;
	while (tmp)
	{
		(*cube)->map[++i] = ft_strdup(tmp->content);
		tmp = tmp->next;
	}
	return (0);
}

int		file_creat_lstmap(char *line, t_game *****cube)
{
	char *new_line;

//	if (file_check_map_prmtrs(cube) == false)
//		return (ERROR); // prmtrs are not correct
//	if (file_check_free_line(line) == false)
//		return (true);	// everything ok, just skeep this line
	new_line = ft_strdup(line); // why ???
	ft_lstadd_back(&(****cube)->head_lstmap, ft_lstnew(new_line));
	return (true);
}

int		file_fill_game(char *line, char **arr_split_line, t_game ****cube)
{
	if (ft_memcmp(arr_split_line[0], "\n", 1) == 0)
		printf("\n");   // fun__
	else if (ft_memcmp(arr_split_line[0], "R", 1) == 0)
		printf("R\n");  // fun_R
	else if (ft_memcmp(arr_split_line[0], "NO", 1) == 0)
		printf("NO\n"); // fun_NO
	else if (ft_memcmp(arr_split_line[0], "SO", 1) == 0)
		printf("SO\n"); // fun_SO
	else if (ft_memcmp(arr_split_line[0], "WE", 1) == 0)
		printf("WE\n"); // fun_WE
	else if (ft_memcmp(arr_split_line[0], "EA", 1) == 0)
		printf("EA\n"); // fun_EA
	else if (ft_memcmp(arr_split_line[0], "S", 1) == 0)
		printf("S\n");  // fun_S
	else if (ft_memcmp(arr_split_line[0], "F", 1) == 0)
		printf("F\n");  // fun_F
	else if (ft_memcmp(arr_split_line[0], "C", 1) == 0)
		printf("C\n");  // fun_C
	else
		file_creat_lstmap(line, &cube);
		//printf("map\n");
	return (0);
}

int		file_parse_line(char *line, t_game ***cube)
{
	char	**splited_line;

	if ((splited_line = ft_split(line, ' ')) == NULL)
		return (ERROR);// ERROR ???
	if (file_fill_game(line, splited_line, &cube) == ERROR)
		return (ERROR);
	ft_free_str_arr(&splited_line);
	ft_free_str(&line);
	return (0);
}

int		file_parser(int fd, t_game **cube)
{
	char 	*line;

	line = NULL;
	while (get_next_line(fd, &line) > 0) // better == 1 ???
	{
		if (file_parse_line(line, &cube) == ERROR)
			return (ERROR);
	}
	if (ft_strlen(line) > 0)
	{
		if (file_parse_line(line, &cube) == ERROR)
			return (ERROR);
	}
	return (0);
}

int		file_main_parsing_function(char *argv_1, t_game *cube)
{
	int		fd;

	if ((fd = open(argv_1, O_RDONLY)) < 0)
		return (ERROR); // NOT OPENED !!!
	if (file_parser(fd, &cube) == ERROR)
		return (ERROR);
		// file_parse_line -> FT_SPLIT malloc ERROR !!!;
		// GNL malloc ERROR ???;
		// file_fill_game ERROR ???;
	file_creat_map(&cube);
	//file_check_map(&cube);
	ft_lstclear(&(cube)->head_lstmap, free);
	if (close(fd) < 0) // NOT CLOSED !!!
		return (ERROR);
}
