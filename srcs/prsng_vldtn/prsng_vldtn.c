/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prsng_vldtn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 02:02:01 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/22 19:47:48 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prsng_vldtn.h"

int	prsng_vldtn(char *argv_1, t_cube3D *cube)
{
	int		fd;

	fd = open(argv_1, O_RDONLY);
	if (fd < 0)
		return (ERROR);
	if (prsng_parse_file(fd, cube) == ERROR)
		return (ERROR);
	if (cube->head_lstmap == NULL)
		my_exit(2);
	prsng_creat_map(&cube);
	vldthn_map(cube);
	ft_lstclear(&(cube)->head_lstmap, free);
	if (close(fd) < 0)
		return (ERROR);
	return (0);
}
