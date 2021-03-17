/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:12:55 by bhatches          #+#    #+#             */
/*   Updated: 2021/03/17 23:39:51 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//static size_t	ft_strlen_sep(const char *str, char sep)
//{
//	size_t i;
//
//	i = 0;
//	while (*str != sep && *str != '\0')
//	{
//		i = i + 1;
//		str++;
//	}
//	return (i);
//}

static int		ft_count_words(char const *s, char c)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (*s != '\0')
	{
		if (*s == c && *s != '\0')
		{
			s++;
		}
		else
		{
			count++;
			s++;
			while (*s != c && *s != '\0')
				s++;
		}
	}
	return (count);
}

//static void		*ft_free_str_arr(char **arr)
//{
//	char	**begin;
//	int		i;
//
//	i = 0;
//	begin = arr;
//	while (arr[i] != NULL)
//	{
//		free(arr[i]);
//		i++;
//	}
//	free(begin);
//	return (NULL);
//}

char			**ft_split(char const *s, char c)
{
	int		n_words;
	char	**arr;
	char	**begin;
	int		i;

	if (s == NULL)
		return (NULL);
	n_words = ft_count_words(s, c);
	if (!(arr = (char**)malloc(sizeof(char*) * (n_words + 1))))
		return (NULL);
	arr[n_words] = NULL;
	begin = arr;
	while (n_words--)
	{
		while (*s == c && *s != '\0')
			s++;
		if (!(*arr = (char*)malloc(sizeof(char) * (ft_strlen_sep(s, c) + 1))))
			return (ft_free_str_arr(&begin));
		i = 0;
		while (*s != c && *s != '\0')
			(*arr)[i++] = *s++;
		(*arr)[i] = '\0';
		arr++;
	}
	return (begin);
}
