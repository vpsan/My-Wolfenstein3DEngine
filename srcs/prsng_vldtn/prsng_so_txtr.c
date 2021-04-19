/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prsng_so_txtr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 21:48:14 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/19 11:11:50 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prsng_vldtn.h"

int	prsng_so_txtr(char **arr_split_line, t_game *cube)
{
	if (cube->map_prmtrs.so_txtr_flag == 1)
		my_exit(5);
	cube->map_prmtrs.so_txtr_flag = 1;
	if (vldthn_count_arrsplitline(arr_split_line) != 2)
		my_exit(5);
	cube->map_prmtrs.so_path = ft_strdup(arr_split_line[1]);
	return (0);
}
