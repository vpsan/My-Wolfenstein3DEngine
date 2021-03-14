#include "strct.h"
#include "mlx.h"

int 	game_start(t_game *cube)
{
	(cube)->wndw.mlx = NULL;
	(cube)->wndw.win = NULL;
	int x = -1;
	int y = -1;

	(cube)->wndw.mlx = mlx_init();
	(cube)->wndw.win = mlx_new_window((cube)->wndw.mlx, 640,
										  480, "test");
	mlx_loop((cube)->wndw.mlx);

	return 0;
}


