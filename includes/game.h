/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strct.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 18:20:35 by bhatches          #+#    #+#             */
/*   Updated: 2021/03/17 21:43:16 by valery           ###   ########.fr       */
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
	void 		*img;
	char 		*addr;
	int			size_line;
	int 		bpp;
	int 		endian;
	int 		width;
	int 		height;
}				t_texture;

typedef struct	s_keys
{
	int 		w;
	int 		a;
	int 		s;
	int 		d;
	int 		left;
	int 		right;
}				t_keys;


typedef struct	s_game
{
	void		*mlx;
	void		*win;
	t_keys		keys;
	t_texture	no_txtr;
	t_texture	so_txtr;
	t_texture 	we_txtr;
	t_texture 	ea_txtr;
//	t_texture	sprts;
//	t_player	plr;
	char		**map;
	t_list		*head_lstmap;
}				t_game;

int		game_map_init(t_game *cube);
int		game_init(t_game *cube);
int		game_start(t_game *cube, int argc);

#endif