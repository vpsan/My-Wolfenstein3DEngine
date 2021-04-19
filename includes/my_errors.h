/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_errors.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:56:18 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/19 16:26:11 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_ERRORS_H
# define MY_ERRORS_H

# include <stdio.h>
# include "libft.h"

void	my_errors_init(void);
void	my_errors_call(int number);
void	my_exit(int number);

char	*g_error_arr[20];

#endif
