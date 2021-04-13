#include "game.h"

int screenshot_fillzeros_bmp(unsigned char *bmp_54arr, t_game *cube)
{
	int i;

	i = 0;
	while (i < 54)
		bmp_54arr[i++] = (unsigned char)0;
	bmp_54arr[0] = 'B';
	bmp_54arr[1] = 'M';

	return (0);
}

int screenshot(t_game *cube)
{
	int				fd;
	unsigned char	bmp_54arr[54];

	printf("START screenshot\n");
	fd = open("screenshot.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	if (fd < 0)
		my_exit(19);
	game_init(cube);
	loop_hook_next_frame(cube);
	screenshot_fillzeros_bmp(bmp_54arr, cube);


	for (int i; i < 54; i++)
		printf("i = %c \n", bmp_54arr[i]);
	printf("END screenshot\n");
	exit(0);
	return (0);
}
