# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/08 17:52:23 by bhatches          #+#    #+#              #
#    Updated: 2021/03/09 15:53:30 by bhatches         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS	=	main.c\
			$(MAP_PARSER)\
			$(GET_NEXT_LINE)

# *********************** LIBFT *********************************************** #	

LIBFT_DIR 	= srcs/libft/
LIBFT 		= $(LIBFT_DIR)libft.a

# *********************** MLX ************************************************* #	

MLX_DIR 	= srcs/mlx/
MLX			= $(MLX_DIR)libmlx.a

# *********************** GET_NEXT_LINE *************************************** #				 

GET_NEXT_LINE_DIR 	= 	srcs/get_next_line/
GET_NEXT_LINE		= 	$(GET_NEXT_LINE_DIR)get_next_line.c\
						$(GET_NEXT_LINE_DIR)get_next_line_utils.c

# *********************** MAP_PARSER ****************************************** #		

MAP_PARSER_DIR		= 	srcs/map_parser/
MAP_PARSER			=	$(MAP_PARSER_DIR)map_parser.c\
			
# *********************** HDRS ************************************************ #	

INCLD 	= 	includes/			
HDRS	=	$(INCLD)libft.h\
			$(INCLD)get_next_line.h\
			$(INCLD)map_parser.h\
			$(INCLD)mlx.h

# ***************************************************************************** #	

OBJ		=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror
CDEBUG	=	-g
OPTFLGS	=	-O2
MLXFLAGS =	-framework OpenGL -framework AppKit

all:		$(NAME)

$(NAME):	$(OBJ)
			make -C $(LIBFT_DIR)
			make -C $(MLX_DIR)
			#$(CC) $(CFLAGS) $(LIBFT) $(OBJ) -o $(NAME)
			$(CC) $(CFLAGS) $(MLXFLAGS) $(MLX) $(LIBFT) $(OBJ) -o $(NAME)
.c.o:
			@$(CC) $(CFLAGS) -I$(INCLD) -c $< -o $(<:.c=.o)
			#$(CC) -I$(INCLD) -c $< -o $(<:.c=.o) gdrive edit

clean:
			make clean -C $(LIBFT_DIR)
			make clean -C $(MLX_DIR)
			@rm -rf $(OBJ)

fclean:		clean
			make fclean -C $(LIBFT_DIR)
			make clean -C $(MLX_DIR)
			@rm -rf $(NAME)

re:			fclean all

#debug:		$(SRCS)
#			@$(CC) $(CDEBUG) -I$(INCLD) $(SRCS) test_printf_main_1.c -o a.out

#norm:		$(SRCS)
#			norminette $(FT_PARSER)* $(FT_PROCESSOR)* $(FT_UTILS)* $(INCLD)* ft_printf.c