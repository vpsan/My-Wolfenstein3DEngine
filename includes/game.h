/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strct.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 18:20:35 by bhatches          #+#    #+#             */
/*   Updated: 2021/03/18 02:36:40 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRCT_H
# define STRCT_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# define SCALE 16
# define ERROR -1

typedef struct	s_texture
{
	void 			*img_ptr;
	char 			*addr_ptr;
	int				size_line;
	int 			bpp;
	int 			endian;
	int 			width;
	int 			height;
}					t_texture;

typedef struct	s_keys
{
	int 			w;
	int 			a;
	int 			s;
	int 			d;
	int 			left;
	int 			right;
}					t_keys;

typedef struct		s_map_prmtrs
{
	int				win_width;
	int 			win_height;
	char 			*no_path;
	char 			*so_path;
	char 			*we_path;
	char 			*ea_path;
	char 			*sprts_path;
}					t_map_prmtrs;

typedef struct	s_game
{
	void			*mlx_ptr;
	void			*win_ptr;
	//	t_player		plr;
	t_keys			keys;
	t_texture		no_txtr;
	t_texture		so_txtr;
	t_texture 		we_txtr;
	t_texture 		ea_txtr;
	t_texture		sprts_txtr;
	t_map_prmtrs	map_prmtrs;
	char			**map;
	t_list			*head_lstmap;
}					t_game;

int		game_map_init(t_game *cube);
int		game_init(t_game *cube);
int		game_start(t_game *cube, int argc);

#endif