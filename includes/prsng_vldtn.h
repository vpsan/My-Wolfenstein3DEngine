/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prsng_vldtn.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:56:31 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/19 11:11:49 by valery           ###   ########.fr       */
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

# define MIN_WIN_HIEGHT 10
# define MIN_WIN_WIDTH 10
# define MAX_WIN_HIEGHT 1480
# define MAX_WIN_WIDTH 2560

int		prsng_vldtn(char *argv_1, t_game *cube);

int		prsng_parse_file(int fd, t_game *cube);
int		prsng_parse_line(char *line, t_game *cube);
int		prsng_fill_game(char *line, char **arr_split_line, t_game *cube);
int		prsng_creat_lstmap(char *line, t_game *cube);
int		prsng_creat_map(t_game **cube);

int		prsng_resolution(char **arr_split_line, t_game *cube);
int		prsng_no_txtr(char **arr_split_line, t_game *cube);
int		prsng_so_txtr(char **arr_split_line, t_game *cube);
int		prsng_we_txtr(char **arr_split_line, t_game *cube);
int		prsng_ea_txtr(char **arr_split_line, t_game *cube);
int		prsng_sprts_txtr(char **arr_split_line, t_game *cube);
int		prsng_color_clng(char **arr_split_line, t_game *cube);
int		prsng_color_flr(char **arr_split_line, t_game *cube);

int		vldthn_count_arrsplitline(char **arr_split_line);
int		vldthn_chech_str_is_digits(char *str, int exit_number);
int		vldthn_make_rgb(int *cube_map_prmtrs_color, int r, int g, int b);
int 	vldthn_count_points(char *str);
int		vldthn_summary_prsng_flags(t_game *cube);
int		vldthn_map(t_game *cube);

#endif
