/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:55:52 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/19 11:11:49 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft.h"
# include "my_errors.h"

# define SCALE 16

# define KEY_ESC 53
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define SPEEDMOVE 0.2
# define SPEEDTRN 0.1

# define MAX_SPRTS_NUM 1000

# define ERROR -1

# define FORBIDDEN_COLOR 0

typedef struct s_frame_prmtrs
{
	void			*img_ptr;
	char			*addr_ptr;
	int				size_line;
	int				bits_per_pixel;
	int				endian;
}					t_frame_prmts;

typedef struct s_keys
{
	int				w;
	int				a;
	int				s;
	int				d;
	int				left;
	int				right;
}					t_keys;

typedef struct s_texture
{
	void			*img_ptr;
	char			*addr_ptr;
	int				size_line;
	int				bits_per_pixel;
	int				endian;
	int				width;
	int				height;
}					t_texture;

typedef struct s_map_prmtrs
{
	int				win_width;
	int				win_height;
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
	char			*sprts_path;
	int				clr_flr;
	int				clr_clng;
	int				resolution_flag;
	int				no_txtr_flag;
	int				so_txtr_flag;
	int				we_txtr_flag;
	int				ea_txtr_flag;
	int				sprts_txtr_flag;
	int				color_flr_flag;
	int				color_clng_flag;
	int				num_player;
}					t_map_prmtrs;

typedef struct s_player
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
}					t_player;

typedef struct s_rcstg
{
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	double			wall_x;
	t_texture		*tex;
	int				tex_x;
	int				tex_y;
	double			tex_step;
	double			tex_pos;
}					t_rcstg;

typedef struct s_sprts
{
	int				num_sprites;
	double			pos_x[MAX_SPRTS_NUM];
	double			pos_y[MAX_SPRTS_NUM];
	int				sprite_order[MAX_SPRTS_NUM];
	double			sprite_dstnc[MAX_SPRTS_NUM];
	double			sprite_x;
	double			sprite_y;
	double			inv_det;
	double			transform_x;
	double			transform_y;
	int				sprite_screen_x;
	int				sprite_height;
	int				sprite_width;
	int				draw_start_y;
	int				draw_end_y;
	int				draw_start_x;
	int				draw_end_x;
	int				stripe;
	int				tex_x;
	int				tex_y;
	int				y;
	int				d;
	int				color;
}					t_sprts;

typedef struct s_game
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_frame_prmts	frame;
	t_player		plr;
	t_keys			keys;
	t_texture		no_txtr;
	t_texture		so_txtr;
	t_texture		we_txtr;
	t_texture		ea_txtr;
	t_texture		sprts_txtr;
	t_map_prmtrs	map_prmtrs;
	t_rcstg			rcstg;
	t_sprts			sprts;
	double			*rcstng_sprts_zbuffer;
	char			**map;
	t_list			*head_lstmap;
}					t_game;

int					game_init(t_game *cube);

int					game_map_init(t_game *cube);
int					game_map_prmtrs_init(t_game *cube);
int					game_window_init(t_game *cube);
int					game_frame_init(t_game *cube);
int					game_player_init(t_game *cube);
int					game_keys_init(t_game *cube);
int					game_textures_init(t_game *cube);
int					game_raycasting_init(t_game *cube);
int					game_sprites_init(t_game *cube);

int					game_start(t_game *cube, int argc);

int					hook_press_on_keys(int key_code, t_game *cube);
int					hook_press_off_keys(int key_code, t_game *cube);
int					hook_close_window(t_game *cube);
int					loop_hook_next_frame(t_game *cube);

int					pre_rcstng_move_player(t_game *cube);
int					move_w(t_game *cube);
int					move_s(t_game *cube);
int					move_a(t_game *cube);
int					move_d(t_game *cube);
int					turn_right(t_game *cube);
int					turn_left(t_game *cube);

int					pre_rcstng_draw_ceiling(t_game *cube);
int					pre_rcstng_draw_floor(t_game *cube);

int					rcstng(t_game *cube);
int					rcstng_init_1(t_game *cube, int x_i);
int					rcstng_init_2(t_game *cube);
int					rcstng_while_hit_not_zero(t_game *cube);
int					rcstng_calculate_distance(t_game *cube);
int					rcstng_calculate_wallx(t_game *cube);
int					rcstng_get_wall_tex(t_game *cube);
int					rcstng_draw_wall(t_game *cube, int x);

int					sprts(t_game *cube);
int					sprts_casting(t_game *cube);
int					sprts_bubble_sort(t_game *cube);
int					sprts_prmtrs_init(t_game *cube, int i);
int					sprts_draw_prmtrs_calculate(t_game *cube);
int					sprts_stripes_draw(t_game *cube);
int					sprts_stripes(t_game *cube);

void				color_pixel_fill(t_frame_prmts *frame,
						int x, int y, int color);

int					screenshot(t_game *cube);

#endif
