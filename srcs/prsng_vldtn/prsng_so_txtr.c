/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prsng_so_txtr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 21:48:14 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/16 21:48:16 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "prsng_vldtn.h"

int 	prsng_so_txtr(char **arr_split_line, t_game *cube)
{
	if (vldthn_count_arrsplitline(arr_split_line) != 2)
		my_exit(5);
	cube->map_prmtrs.so_path = ft_strdup(arr_split_line[1]);
	return (0);
}

