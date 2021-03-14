# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/08 17:52:23 by bhatches          #+#    #+#              #
#    Updated: 2021/03/13 12:07:11 by valery           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS	=	main.c \
			$(FILE_PARSE_FILE) \
			$(GET_NEXT_LINE) \
			$(LIBFT_SRCS) \
			$(GAME) \

# *********************** HDRS ************************************************ #

INCLD 	= 	includes/
HDRS	=	$(INCLD)libft.h\
			$(INCLD)get_next_line.h\
			$(INCLD)file_parser.h\
			$(INCLD)mlx.h

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

# *********************** GAME ************************************************ #

GAME_DIR 	= 	srcs/game/
GAME		= 	$(GAME_DIR)game_init.c\
				$(GAME_DIR)game_start.c

# *********************** FILE_PARSE_FILE ****************************************** #

FILE_PARSE_FILE_DIR		= 	srcs/file_parse_file/
FILE_PARSE_FILE			=	$(FILE_PARSE_FILE_DIR)file_parse_file.c\

# ***************************************************************************** #	

OBJ		=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -g
CDEBUG	=	-g
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
