/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_pixel_fill.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 01:57:51 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/12 19:00:31 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	color_pixel_fill(t_frame_prmts *frame, int x, int y, int color)
{
	char	*new_addr_ptr;

	new_addr_ptr = frame->addr_ptr +
			(y * frame->size_line + x * (frame->bits_per_pixel / 8));
	*(unsigned int*)new_addr_ptr = color;
}
