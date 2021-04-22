/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vldthn_make_rgb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 15:35:25 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/22 19:47:48 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prsng_vldtn.h"

int	vldthn_make_rgb(int *cube_map_prmtrs_color, int r, int g, int b)
{
	int	result_rgb_color;

	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		my_exit(9);
	result_rgb_color = (r << 16 | g << 8 | b);
	*cube_map_prmtrs_color = result_rgb_color;
	return (0);
}
