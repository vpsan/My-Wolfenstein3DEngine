# include "prsng_vldtn.h"

int		prsng_vldtn(char *argv_1, t_game *cube)
{
	int		fd;

	if ((fd = open(argv_1, O_RDONLY)) < 0)
		return (ERROR); // NOT OPENED !!!
	if (prsng_parse_file(fd, &cube) == ERROR)
		return (ERROR);
	// prsng_parse_line -> FT_SPLIT malloc ERROR !!!;
	// GNL malloc ERROR ???;
	// prsng_fill_game ERROR ???;
	prsng_creat_map(&cube);
	//file_check_map(&cube);
	ft_lstclear(&(cube)->head_lstmap, free);
	if (close(fd) < 0) // NOT CLOSED !!!
		return (ERROR);
	return (0);
}
