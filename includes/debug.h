/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:55:43 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/12 23:00:39 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include "libft.h"
# include "get_next_line.h"
# include "my_errors.h"
# include "prsng_vldtn.h"
# include "game.h"

int		debug_print_check_map(t_game *cube);
void	debug_fill_map_instead_parsing(t_game *cube);
int		debug_map_prmtrs_init(t_game *cube);
int 	debug_sprts_init(t_game *cube);
char	*g_new_map[5];

#endif
