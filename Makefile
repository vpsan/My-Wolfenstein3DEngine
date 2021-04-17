# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/08 17:52:23 by bhatches          #+#    #+#              #
#    Updated: 2021/04/17 14:15:46 by valery           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS	=	$(MAIN) \
			$(LIBFT_SRCS) \
			$(GET_NEXT_LINE) \
			$(MY_ERRORS) \
			$(PRSNG_VLDTN) \
			$(GAME) \
			$(DEBUG_FUN)

# *********************** MAIN ************************************************ #

MAIN_DIR 	= 	srcs/
MAIN		= 	$(MAIN_DIR)main.c

# *********************** HDRS ************************************************ #

INCLD 	= 	includes/
HDRS	=	$(INCLD)mlx.h \
			$(INCLD)libft.h \
			$(INCLD)get_next_line.h \
			$(INCLD)my_errors.h \
			$(INCLD)prsng_vldtn.h\
			$(INCLD)game.h

# *********************** LIBFT *********************************************** #	

LIBFT_DIR 	= srcs/libft/
#LIBFT 		= $(LIBFT_DIR)libft.a
LIBFT_SRCS	= $(LIBFT_DIR)ft_memset.c\
		  $(LIBFT_DIR)ft_bzero.c\
		  $(LIBFT_DIR)ft_memcpy.c\
		  $(LIBFT_DIR)ft_memccpy.c\
		  $(LIBFT_DIR)ft_memmove.c\
		  $(LIBFT_DIR)ft_memchr.c\
		  $(LIBFT_DIR)ft_memcmp.c\
		  $(LIBFT_DIR)ft_strlen.c\
		  $(LIBFT_DIR)ft_isalpha.c\
		  $(LIBFT_DIR)ft_isdigit.c\
		  $(LIBFT_DIR)ft_isalnum.c\
		  $(LIBFT_DIR)ft_isascii.c\
		  $(LIBFT_DIR)ft_isprint.c\
		  $(LIBFT_DIR)ft_toupper.c\
		  $(LIBFT_DIR)ft_tolower.c\
		  $(LIBFT_DIR)ft_strrchr.c\
		  $(LIBFT_DIR)ft_strchr.c\
		  $(LIBFT_DIR)ft_strncmp.c\
		  $(LIBFT_DIR)ft_strlcpy.c\
		  $(LIBFT_DIR)ft_strlcat.c\
		  $(LIBFT_DIR)ft_strnstr.c\
		  $(LIBFT_DIR)ft_atoi.c\
		  $(LIBFT_DIR)ft_calloc.c\
		  $(LIBFT_DIR)ft_strdup.c\
		  $(LIBFT_DIR)ft_putchar_fd.c\
		  $(LIBFT_DIR)ft_substr.c\
		  $(LIBFT_DIR)ft_strjoin.c\
		  $(LIBFT_DIR)ft_strtrim.c\
		  $(LIBFT_DIR)ft_putstr_fd.c\
		  $(LIBFT_DIR)ft_putendl_fd.c\
		  $(LIBFT_DIR)ft_putnbr_fd.c\
		  $(LIBFT_DIR)ft_itoa.c\
		  $(LIBFT_DIR)ft_strmapi.c\
		  $(LIBFT_DIR)ft_split.c \
		  $(BON) \
		  $(MyNew)

BON		= $(LIBFT_DIR)ft_lstnew.c\
		  $(LIBFT_DIR)ft_lstadd_front.c\
		  $(LIBFT_DIR)ft_lstdelone.c\
		  $(LIBFT_DIR)ft_lstsize.c \
		  $(LIBFT_DIR)ft_lstlast.c \
		  $(LIBFT_DIR)ft_lstadd_back.c\
		  $(LIBFT_DIR)ft_lstclear.c\
		  $(LIBFT_DIR)ft_lstiter.c\
	      $(LIBFT_DIR)ft_lstmap.c

MyNew	= $(LIBFT_DIR)ft_strlen_sep.c \
		  $(LIBFT_DIR)ft_free_str.c \
		  $(LIBFT_DIR)ft_free_str_arr.c


# *********************** GET_NEXT_LINE *************************************** #

GET_NEXT_LINE_DIR 	= 	srcs/get_next_line/
GET_NEXT_LINE		= 	$(GET_NEXT_LINE_DIR)get_next_line.c\
						$(GET_NEXT_LINE_DIR)get_next_line_utils.c

# *********************** MLX ************************************************* #	

MLX_DIR 	= srcs/mlx/
MLX			= $(MLX_DIR)libmlx.a

# *********************** MY_ERRORS ******************************************* #

MY_ERRORS_DIR 	= 	srcs/my_errors/
MY_ERRORS		= 	$(MY_ERRORS_DIR)my_errors.c

# *********************** PRSNG_VLDTN ***************************************** #

PRSNG_VLDTN_DIR	= 	srcs/prsng_vldtn/
PRSNG_VLDTN		=	$(PRSNG_VLDTN_DIR)prsng_vldtn.c\
					$(PRSNG_VLDTN_DIR)prsng.c\
					$(PRSNG_VLDTN_DIR)prsng_resolution.c\
					$(PRSNG_VLDTN_DIR)prsng_no_txtr.c\
					$(PRSNG_VLDTN_DIR)prsng_so_txtr.c\
					$(PRSNG_VLDTN_DIR)prsng_we_txtr.c\
					$(PRSNG_VLDTN_DIR)prsng_ea_txtr.c\
					$(PRSNG_VLDTN_DIR)prsng_sprts_txtr.c\
					$(PRSNG_VLDTN_DIR)prsng_color_clng.c\
					$(PRSNG_VLDTN_DIR)prsng_color_flr.c\
					$(PRSNG_VLDTN_DIR)vldthn_count_split_arr.c\
					$(PRSNG_VLDTN_DIR)vldthn_chech_str_is_digits.c\
					$(PRSNG_VLDTN_DIR)vldthn_map.c\

# *********************** GAME ************************************************ #

GAME_DIR 	= 	srcs/game/
GAME		= 	$(GAME_DIR)game_init.c\
				$(GAME_DIR)game_map_init.c\
				$(GAME_DIR)game_map_prmtrs_init.c\
				$(GAME_DIR)game_window_init.c\
				$(GAME_DIR)game_frame_init.c\
				$(GAME_DIR)game_player_init.c\
				$(GAME_DIR)game_keys_init.c\
				$(GAME_DIR)game_textures_init.c\
				$(GAME_DIR)game_raycasting_init.c\
				$(GAME_DIR)game_sprites_init.c\
				$(GAME_DIR)game_start.c\
				$(GAME_DIR)loop_hook_next_frame.c\
				$(GAME_DIR)color_pixel_fill.c\
				$(GAME_DIR)player_move.c\
				$(GAME_DIR)player_turn.c\
				$(GAME_DIR)rcstng.c\
				$(GAME_DIR)rcstng_init.c\
				$(GAME_DIR)rcstng_while_hit_not_zero.c\
				$(GAME_DIR)rcstng_calculate_distance.c\
				$(GAME_DIR)rcstng_calculate_wallx.c\
				$(GAME_DIR)rcstng_draw_wall.c\
				$(GAME_DIR)rcstng_get_wall_tex.c\
				$(GAME_DIR)sprts.c\
				$(GAME_DIR)sprts_casting.c\
				$(GAME_DIR)sprts_bubble_sort.c\
				$(GAME_DIR)sprts_prmtrs_init.c\
				$(GAME_DIR)sprts_draw_prmtrs_calculate.c\
				$(GAME_DIR)sprts_stripes.c\
				$(GAME_DIR)screenshot.c\

# *********************** DEBUG_FUN ******************************************* #

DEBUG_DIR 	= 	srcs/debug/
DEBUG_FUN	= 	$(DEBUG_DIR)debug_print_check_map.c\
				$(DEBUG_DIR)debug_fill_map_instead_parsing.c\
				$(DEBUG_DIR)debug_preparsing_init.c\

# ***************************************************************************** #

OBJ		=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -g
CDEBUG	=	-g #-fsanitize=address
OPTFLGS	=	-O2
MLXFLAGS =	-framework OpenGL -framework AppKit

all:		$(NAME)

$(NAME):	$(OBJ)
			#make -C $(LIBFT_DIR)
			make -C $(MLX_DIR)
			$(CC) $(CDEBUG) $(MLXFLAGS) $(MLX) $(OBJ) -o $(NAME)
			     #$(CFLAGS)					#$(LIBFT)
.c.o:
			@$(CC) $(CDEBUG) -I$(INCLD) -c $< -o $(<:.c=.o)
			      #$(CFLAGS)	

clean:
			#make clean -C $(LIBFT_DIR)
			make clean -C $(MLX_DIR)
			@rm -rf $(OBJ)

fclean:		clean
			#make fclean -C $(LIBFT_DIR)
			make clean -C $(MLX_DIR)
			@rm -rf $(NAME)

re:			fclean all
