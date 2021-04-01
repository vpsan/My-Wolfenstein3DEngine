/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 21:41:47 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/01 22:17:29 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	int		i;
	int		start_index;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	while (ft_strchr(set, s1[i]) != NULL && s1[i] != '\0')
	{
		i++;
	}
	start_index = i;
	while (s1[i] != '\0')
	{
		i++;
	}
	i--;
	while (ft_strchr(set, s1[i]) != NULL && i > start_index)
	{
		i--;
	}
	if (!(s = ft_substr(s1, start_index, i - start_index + 1)))
		return (NULL);
	return (s);
}
