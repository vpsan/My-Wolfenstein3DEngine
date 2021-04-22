/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vldthn_empty_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 16:22:15 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/22 19:47:48 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prsng_vldtn.h"

int	vldthn_empty_line(char *line)
{
	int	i;

	i = 0;
	if (line == NULL)
		return (0);
	if (*line == '\0')
		return (0);
	while (line[i] != '\0')
	{
		if (line[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}
