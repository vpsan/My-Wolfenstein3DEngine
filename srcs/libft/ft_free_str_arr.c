/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_str_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 18:35:25 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/19 13:36:05 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION
**	ft_free_str_arr() must free up malloc'ed memory of arr and set arr as NULL.
**	RETURN VALUES
**	ft_free_str_arr() returns (void*)NULL.
*/

void	*ft_free_str_arr(char ***arr)
{
	int	i;

	if (arr == NULL || *arr == NULL)
		return (NULL);
	i = 0;
	if ((*arr) != NULL)
	{
		while ((*arr)[i] != NULL)
		{
			if ((*arr)[i] != NULL)
			{
				free((*arr)[i]);
				(*arr)[i] = NULL;
			}
			i++;
		}
		free(*arr);
		*arr = NULL;
	}
	return (NULL);
}
