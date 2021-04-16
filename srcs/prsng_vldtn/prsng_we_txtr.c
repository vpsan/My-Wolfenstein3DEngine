/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prsng_we_txtr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 21:48:22 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/16 21:48:23 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prsng_vldtn.h"

int 	prsng_we_txtr(char **arr_split_line, t_game *cube)
{
	if (vldthn_count_arrsplitline(arr_split_line) != 2)
		my_exit(6);
	cube->map_prmtrs.we_path = ft_strdup(arr_split_line[1]);
	return (0);
}
