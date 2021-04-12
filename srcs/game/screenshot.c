#include "game.h"

int screenshot(t_game *cube)
{
	int				fd;
	unsigned char	bmp_arr[54];

	printf("screenshot\n");
	fd = open("screenshot.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	if (fd < 0)
		my_exit(19);
	game_init(&cube);
	loop_hook_next_frame(cube);
//	create_bmp(&bmp_arr);

	exit(0);
	return (0);
}
