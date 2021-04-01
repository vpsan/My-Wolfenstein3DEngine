/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prsng_vldtn.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:56:31 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/01 16:37:58 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRSNG_VLDTN_H
# define PRSNG_VLDTN_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"
# include "game.h"

int		prsng_vldtn(char *argv_1, t_game *cube);

int		prsng_parse_file(int fd, t_game **cube);
int		prsng_parse_line(char *line, t_game ***cube);
int		prsng_fill_game(char *line, char **arr_split_line, t_game ****cube);
int		prsng_creat_lstmap(char *line, t_game *****cube);
int		prsng_creat_map(t_game **cube);

#endif
