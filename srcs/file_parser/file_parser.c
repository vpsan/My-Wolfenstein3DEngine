#include "libft.h"
#include "get_next_line.h"
#include "strct.h"
#include <stdio.h>

char	**make_map(t_list **head, int size)
{
	char 	**map = ft_calloc(size + 1, sizeof(char *));
	int		i = -1;
	t_list	*tmp = *head;

	while (tmp)
	{
		map[++i] = tmp->content;
		tmp= tmp->next;
	}
	i = -1;
	while (map[++i])
		printf("%s\n", map[i]);
	return (map);
}

int file_parser(int fd, t_game *cube)
{
	char 	*line = NULL;
	t_list	*head = NULL;

	while (get_next_line(fd, &line))
		ft_lstadd_back(&head, ft_lstnew(line));
	ft_lstadd_back(&head, ft_lstnew(line));
	make_map(&head, ft_lstsize(head));
	return (0);
}
