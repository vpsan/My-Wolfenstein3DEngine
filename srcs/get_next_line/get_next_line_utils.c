/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 12:12:15 by bhatches          #+#    #+#             */
/*   Updated: 2020/11/30 14:07:19 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

//char		*ft_strchr(const char *str, int value)
//{
//	while (*str != '\0')
//	{
//		if (*str == (char)value)
//		{
//			return ((char*)str);
//		}
//		str++;
//	}
//	if ((char)value == '\0')
//	{
//		return ((char*)str);
//	}
//	return (NULL);
//}

/*
**	DESCRIPTION
**	ft_strlen_sep() counts length of the string till the first
**	occurrence of character value.
**	RETURN VALUES
**	ft_strlen_sep() returns type size_t.
*/

//size_t		ft_strlen_sep(const char *str, int value)
//{
//	size_t	i;
//
//	i = 0;
//	if (str == NULL)
//		return (0);
//	while (*str != '\0' && *str != value)
//	{
//		i = i + 1;
//		str++;
//	}
//	return (i);
//}

/*
**	DESCRIPTION
**	ft_free_str() must free up malloc'ed memory of s and set s as NULL.
**	RETURN VALUES
**	ft_free_str() returns 0.
*/

//int			ft_free_str(char **s)
//{
//	if (*s != NULL)
//	{
//		free(*s);
//	}
//	*s = NULL;
//	return (0);
//}

/*
**	DESCRIPTION
**	ft_leftjoin_sep() leftjoins the string s2 to the string s1
**	till the first occurrence of character value in s2 ans free up memory of s1.
**	RETURN VALUES
**	ft_leftjoin_sep() returns a new malloc'ed s1 with joined s2 till
**	the first occurrence of character value in s2.
*/

char		*ft_leftjoin_sep(char *s1, char *s2, int value)
{
	char		*s;
	char		*s_begin;
	char		*s1_begin;
	size_t		s1_len;
	size_t		s2_len;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	s1_len = ft_strlen_sep(s1, '\0');
	s2_len = ft_strlen_sep(s2, value);
	s = (char*)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	s_begin = s;
	s1_begin = (char*)s1;
	while (s1 != NULL && *s1 != '\0')
		*s++ = *s1++;
	while (s2 != NULL && *s2 != '\0' && *s2 != value)
		*s++ = *s2++;
	*s = '\0';
	ft_free_str(&s1_begin);
	return (s_begin);
}

/*
**	DESCRIPTION
**	ft_rewrite_str() rewrites the string s after the first
**	occurrence of character value, free up memory of s.
**	RETURN VALUES
**	ft_rewrite_str() returns a new malloc'ed s after
**	the first occurrence of character value.
*/

char		*ft_rewrite_str(char *s, int value)
{
	char	*ptr_c;
	char	*new_s;
	char	*new_s_begin;

	if ((ptr_c = ft_strchr(s, value)) == NULL)
		return (s);
	else
	{
		new_s = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (new_s == NULL)
			return (NULL);
		new_s_begin = new_s;
		ptr_c++;
		while (*ptr_c != '\0')
			*new_s++ = *ptr_c++;
		*new_s = '\0';
		ft_free_str(&s);
		return (new_s_begin);
	}
}
