#include "my_errors.h"

void	my_errors_init(void)
{
	error_arr[0] = "Error\n Error without name.\n";
	error_arr[1] = "Error\n Invalid argc or argv.\n";
	error_arr[2] = "Error\n Parsing file error.\n";
	error_arr[3] = "Error\n game_window_init error.\n";
	return ;
}

void	my_errors_call(int number)
{
	write(2, error_arr[number], ft_strlen(error_arr[number]));
	return ;
}