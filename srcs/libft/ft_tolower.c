/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:50:44 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/06 12:44:23 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tolower(int value)
{
	if (value >= 65 && value <= 90)
	{
		return (value + 32);
	}
	else
	{
		return (value);
	}
}
