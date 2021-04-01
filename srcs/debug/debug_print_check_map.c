/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print_check_map.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 01:57:35 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/02 01:57:37 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

int		debug_print_check_map(t_game *cube)
{
	int i;

	i = 0;
	while (cube->map[i] != NULL)
	{
		printf("%s\n", cube->map[i]);
		i++;
	}
	return (0);
}
