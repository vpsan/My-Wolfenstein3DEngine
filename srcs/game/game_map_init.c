/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 01:58:33 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/22 19:47:48 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	game_map_init(t_cube3D *cube)
{
	cube->map = NULL;
	cube->head_lstmap = NULL;
	return (0);
}
