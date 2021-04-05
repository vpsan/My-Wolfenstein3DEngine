#include "prsng_vldtn.h"

int 	vldthn_count_arrsplitline(char **arr_split_line)
{
	int i;

	i = 0;
	while (*arr_split_line != NULL)
	{
		i++;
		arr_split_line++;
	}
	return (i);
}
