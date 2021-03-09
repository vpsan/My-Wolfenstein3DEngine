#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "libft.h"

int map_parser(void)
{
	char	*line;
	int		fd;
    int		i;
    int		j;
	
	fd = open("/Users/valery/Desktop/file1", O_RDONLY);
	if (fd == -1)
	{
		printf("Cannot read file.");
		return (0);
	}

	i = 0;
	j = 0;
	//line = NULL;
	while ((i = get_next_line(fd, &line)) != 0) 
	{
		if (i == -1)
		{
			printf("ERROR\n");
			return (0);
		}
		printf("line: %s\n", line);
        //line = NULL;
		free(line);
        printf("Return function value: %d\n", i);
		printf("Number of function calls: %d\n", j);
        printf("\n");
		j++;
	}
    printf("line: %s\n", line);
	//line = NULL;
	free(line);
    printf("Return function value: %d\n", i);
	printf("Number of function calls: %d\n", j);
	printf("\n");

	return (0);
}