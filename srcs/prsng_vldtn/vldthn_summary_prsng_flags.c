/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vldthn_summary_prsng_flags.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:05:42 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/19 11:11:50 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prsng_vldtn.h"

int	vldthn_summary_prsng_flags(t_game *cube)
{
	if (cube->map_prmtrs.resolution_flag != 1
		|| cube->map_prmtrs.no_txtr_flag != 1
		|| cube->map_prmtrs.so_txtr_flag != 1
		|| cube->map_prmtrs.we_txtr_flag != 1
		|| cube->map_prmtrs.ea_txtr_flag != 1
		|| cube->map_prmtrs.sprts_txtr_flag != 1
		|| cube->map_prmtrs.color_clng_flag != 1
		|| cube->map_prmtrs.color_flr_flag != 1)
		return (false);
	return (true);
}
