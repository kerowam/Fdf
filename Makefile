# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 23:20:55 by gfredes-          #+#    #+#              #
#    Updated: 2024/01/04 02:23:11 by gfredes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

BONUS = fdf_bonus

CFLAGS = -Wall -Wextra -Werror

CLEAN = rm -f

SRC =	read_map.c \
		read_map_utils.c \
		draw.c \
		draw_utils.c \
		main.c \
		ft_atoi_base.c

SRC_BONUS =	read_map_bonus.c \
			read_map_utils_bonus.c \
			draw_bonus.c \
			draw_utils_bonus.c \
			main_bonus.c \
			ft_atoi_base.c

CC = gcc

OBJT = $(SRC:.c=.o)

OBJT_BONUS = $(SRC_BONUS:.c=.o)

LIBFT = libft/libft.a

MINILIBX = minilibx-linux/libmlx.a

all: $(LIBFT) $(MINILIBX) $(NAME)

$(LIBFT):
	make -C ./libft

$(MINILIBX):
	make -C ./minilibx-linux

$(NAME): $(LIBFT) $(MINILIBX) $(OBJT)
	$(CC) $(CFLAGS) $(SRC) $(MINILIBX) $(LIBFT) -lGL -lX11 -lXext -lm -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(LIBFT) $(MINILIBX) $(OBJT_BONUS)
	$(CC) $(CFLAGS) $(SRC_BONUS) $(MINILIBX) $(LIBFT) -lGL -lX11 -lXext -lm -o $(BONUS)

clean:
	$(CLEAN) $(OBJT) $(OBJT_BONUS)
	make -C ./libft clean
	make -C ./minilibx-linux clean

fclean: clean
	$(CLEAN) $(NAME) $(BONUS)
	make -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re bonus