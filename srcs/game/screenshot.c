#include "game.h"

int screenshot_creat_bmp(unsigned char *bmp_54arr, t_game *cube, int size)
{
	int i;

	i = 0;
	while (i < 54)
		bmp_54arr[i++] = (unsigned char)0;
	bmp_54arr[0] = 'B';
	bmp_54arr[1] = 'M';
	bmp_54arr[2] = (unsigned char)(size);
	bmp_54arr[3] = (unsigned char)(size >> 8);
	bmp_54arr[4] = (unsigned char)(size >> 16);
	bmp_54arr[5] = (unsigned char)(size >> 24);
	bmp_54arr[10] = (unsigned char)54;
	bmp_54arr[14] = (unsigned char)40;
	bmp_54arr[18] = (unsigned char)cube->map_prmtrs.win_width;
	bmp_54arr[19] = (unsigned char)(cube->map_prmtrs.win_width >> 8);
	bmp_54arr[20] = (unsigned char)(cube->map_prmtrs.win_width >> 16);
	bmp_54arr[21] = (unsigned char)(cube->map_prmtrs.win_width >> 24);
	bmp_54arr[22] = (unsigned char)cube->map_prmtrs.win_height;
	bmp_54arr[23] = (unsigned char)(cube->map_prmtrs.win_height >> 8);
	bmp_54arr[24] = (unsigned char)(cube->map_prmtrs.win_height  >> 16);
	bmp_54arr[25] = (unsigned char)(cube->map_prmtrs.win_height  >> 24);
	bmp_54arr[26] = (unsigned char)1;
	bmp_54arr[28] = (unsigned char)24;
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
	screenshot_creat_bmp(bmp_54arr, cube, cube->map_prmtrs.win_width *
											cube->map_prmtrs.win_height + 54);
	for (int i; i < 54; i++)
		printf("i = %c \n", bmp_54arr[i]);
	printf("END screenshot\n");
	exit(0);
	return (0);
}