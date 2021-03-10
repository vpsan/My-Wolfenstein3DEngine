# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/08 17:52:23 by bhatches          #+#    #+#              #
#    Updated: 2021/03/10 14:49:43 by bhatches         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS	=	main.c\
			$(FILE_PARSER)\
			$(GET_NEXT_LINE)

# *********************** HDRS ************************************************ #

INCLD 	= 	includes/
HDRS	=	$(INCLD)libft.h\
			$(INCLD)get_next_line.h\
			$(INCLD)file_parser.h\
			$(INCLD)mlx.h

# *********************** LIBFT *********************************************** #	

LIBFT_DIR 	= srcs/libft/
LIBFT 		= $(LIBFT_DIR)libft.a

# *********************** GET_NEXT_LINE *************************************** #

GET_NEXT_LINE_DIR 	= 	srcs/get_next_line/
GET_NEXT_LINE		= 	$(GET_NEXT_LINE_DIR)get_next_line.c\
						$(GET_NEXT_LINE_DIR)get_next_line_utils.c

# *********************** MLX ************************************************* #	

MLX_DIR 	= srcs/mlx/
MLX			= $(MLX_DIR)libmlx.a

# *********************** FILE_PARSER ****************************************** #

FILE_PARSER_DIR		= 	srcs/file_parser/
FILE_PARSER			=	$(FILE_PARSER_DIR)file_parser.c\

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
			$(CC) $(CDEBUG) $(MLXFLAGS) $(MLX) $(LIBFT) $(OBJ) -o $(NAME)
			     #$(CFLAGS)
.c.o:
			@$(CC) $(CDEBUG) -I$(INCLD) -c $< -o $(<:.c=.o)
			      #$(CFLAGS)	

clean:
			make clean -C $(LIBFT_DIR)
			make clean -C $(MLX_DIR)
			@rm -rf $(OBJ)

fclean:		clean
			make fclean -C $(LIBFT_DIR)
			make clean -C $(MLX_DIR)
			@rm -rf $(NAME)

re:			fclean all
