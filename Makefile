# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: waelhamd <waelhamd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/22 02:12:13 by waelhamd          #+#    #+#              #
#    Updated: 2022/02/23 02:51:52 by waelhamd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = fdf.c bresenham.c draw.c ft_atoi_hex.c ft_atoi.c ft_data.c \
		ft_handle_exit.c ft_split.c ft_substr.c ft_zoom.c get_next_line_utils.c \
		get_next_line.c init_mandatory.c isometric.c memory_allocate.c
OBJ	   = $(SRC:.c=.o)

SRC_BONUS = fdf_bonus.c bresenham.c draw.c ft_atoi_hex.c ft_atoi.c ft_data.c \
		ft_handle_exit.c ft_split.c ft_substr.c ft_zoom.c get_next_line_utils.c \
		get_next_line.c init_bonus.c isometric.c memory_allocate.c \
		key_fonction_bonus.c handle_keys_bonus.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)


CFLAGS = -Wall -Wextra -Werror
CC     = gcc

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
MATH_FLAGS = -lm

NAME = fdf
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(MATH_FLAGS) $(MLX_FLAGS) $(OBJ) -o $@

%.o: %.c 
	$(CC) $(CFLAGS) -c $<

bonus: $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(MATH_FLAGS) $(MLX_FLAGS) $(OBJ_BONUS) -o $(NAME)

clean:
	rm -rf $(OBJ) $(OBJ_BONUS)
		
fclean: clean
	rm -rf $(NAME)

re: fclean all