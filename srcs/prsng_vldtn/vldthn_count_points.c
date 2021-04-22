/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vldthn_count_points.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 15:35:14 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/22 19:47:48 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prsng_vldtn.h"

int	vldthn_count_points(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		if (*str == ',')
			i++;
		str++;
	}
	return (i);
}
