/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prsng.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 02:01:51 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/03 12:14:10 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "prsng_vldtn.h"

int 	prsng_creat_map(t_game **cube)
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

int		prsng_creat_lstmap(char *line, t_game *cube)
{
	char *new_line;

//	if (file_check_map_prmtrs(cube) == false)
//		return (ERROR); // prmtrs are not correct
//	if (file_check_free_line(line) == false)
//		return (true);	// everything ok, just skeep this line
	new_line = ft_strdup(line);
	ft_lstadd_back(&cube->head_lstmap, ft_lstnew(new_line));
	return (true);
}

int		prsng_fill_game(char *line, char **arr_split_line, t_game *cube)
{
	if (ft_memcmp(arr_split_line[0], "R", 1) == 0)
		prsng_resolution(arr_split_line, cube);
	else if (ft_memcmp(arr_split_line[0], "NO", 1) == 0)
		prsng_no_txtr(arr_split_line, cube);
	else if (ft_memcmp(arr_split_line[0], "SO", 1) == 0)
		prsng_so_txtr(arr_split_line, cube);
	else if (ft_memcmp(arr_split_line[0], "WE", 1) == 0)
		prsng_we_txtr(arr_split_line, cube);
	else if (ft_memcmp(arr_split_line[0], "EA", 1) == 0)
		prsng_ea_txtr(arr_split_line, cube);
	else if (ft_memcmp(arr_split_line[0], "S", 1) == 0)
		prsng_sprts_txtr(arr_split_line, cube);
	else if (ft_memcmp(arr_split_line[0], "F", 1) == 0)
		prsng_color_clng(arr_split_line, cube);
	else if (ft_memcmp(arr_split_line[0], "C", 1) == 0)
		prsng_color_flr(arr_split_line, cube);
	else
		prsng_creat_lstmap(line, cube);
	return (0);
}

int		prsng_parse_line(char *line, t_game *cube)
{
	char	**splited_line;

	if ((splited_line = ft_split(line, ' ')) == NULL)
		return (ERROR);// ERROR ???
	if (prsng_fill_game(line, splited_line, cube) == ERROR)
		return (ERROR);
	ft_free_str_arr(&splited_line);
	ft_free_str(&line);
	return (0);
}

int		prsng_parse_file(int fd, t_game *cube)
{
	char 	*line;

	line = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		if (prsng_parse_line(line, cube) == ERROR)
			return (ERROR);
	}
	if (ft_strlen(line) > 0)
	{
		if (prsng_parse_line(line, cube) == ERROR)
			return (ERROR);
	}
	return (0);
}
