/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prsng_sprts_txtr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 21:48:17 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/20 18:29:22 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prsng_vldtn.h"

int 	prsng_sprts_txtr(char **arr_split_line, t_cube3D *cube)
{
	if (cube->map_prmtrs.sprts_txtr_flag == 1)
		my_exit(8);
	cube->map_prmtrs.sprts_txtr_flag = 1;
	if (vldthn_count_arrsplitline(arr_split_line) != 2)
		my_exit(8);
	cube->map_prmtrs.sprts_path = ft_strdup(arr_split_line[1]);
	return (0);
}
