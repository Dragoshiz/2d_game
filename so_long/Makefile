# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 12:11:52 by dimbrea           #+#    #+#              #
#    Updated: 2023/01/30 11:48:22 by dimbrea          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

RM = rm -f

FLAGS = -Wall -Werror -Wextra -g

AF = ar rc

MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit

SRCS =	map_utils/check_map.c \
		map_utils/map_err_msg.c \
		map_utils/put_img.c\
		game_cmd/engine.c\
		game_cmd/movement.c\
		main.c \


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
				make -C libft
				make -C mlx
				cp ./libft/libft.a libft_so_long.a
				$(AF) libft_so_long.a $(OBJS)
				$(CC) $(FLAGS) ./libft_so_long.a ./mlx/libmlx.a $(MLX) $(OBJS) -g -o $(NAME)

clean:
	$(RM) $(OBJS) 
	make clean -C libft
	make clean -C mlx

fclean: clean
	$(RM) $(NAME)
	$(RM) libft_so_long.a
	make fclean -C libft
	make clean -C mlx
	

re: fclean all

PHONY: all clean fclean re