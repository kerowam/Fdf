# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 23:20:55 by gfredes-          #+#    #+#              #
#    Updated: 2024/01/04 00:10:36 by gfredes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CFLAGS = -Wall -Wextra -Werror

CLEAN = rm -f

SRC =	read_map.c \
		read_map_utils.c \
		draw.c \
		draw_utils.c \
		main.c \
		ft_atoi_base.c

CC = gcc

OBJT = $(SRC:.c=.o)

LIBFT = libft/libft.a

MINILIBX = minilibx-linux/libmlx.a

all: $(LIBFT) $(MINILIBX) $(NAME)

$(LIBFT):
	make -C ./libft

$(MINILIBX):
	make -C ./minilibx-linux

$(NAME): $(LIBFT) $(MINILIBX) $(OBJT)
	$(CC) $(CFLAGS) $(SRC) $(MINILIBX) $(LIBFT) -lGL -lX11 -lXext -lm -o $(NAME)

clean:
	$(CLEAN) $(OBJT)
	make -C ./libft clean
	make -C ./minilibx-linux clean

fclean: clean
	$(CLEAN) $(NAME)
	make -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re