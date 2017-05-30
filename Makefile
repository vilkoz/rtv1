# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrybalko <vrybalko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/23 14:08:11 by vrybalko          #+#    #+#              #
#    Updated: 2017/03/25 17:30:15 by vrybalko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1

IDIR = includes/

VPATH = src:includes

BIN_DIR = bin/

FLAGS = -Wall -Wextra -Werror -I$(IDIR) -g

FLAGS_MLX = -lmlx -framework OpenGl -framework AppKit

FLAGS_X11 = -lmlx -lXext -lX11 -lm

LIB = libft/libft.a

SRCS = main.c						\
       ft_hooks.c				\
			 ft_img_px_put.c	\
			 ft_mlx_events.c	\
			 ft_mlx_init.c		\
			 ray_tools.c			\
			 ray_tools1.c			\
			 ray_tools2.c			\
			 render.c					\
			 scene.c					\
			 sphere.c					\
			 cylinder.c				\
			 cone.c						\
			 color.c					\
			 colors1.c				\
			 plane.c					\
			 read_file.c			\
			 read_file1.c			\
			 read_file2.c			\

BINS = $(addprefix $(BIN_DIR), $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(BINS)
	make -C libft/
	gcc -o $(NAME) $(BINS) $(FLAGS) $(FLAGS_MLX) $(LIB)

$(BIN_DIR)%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

clean:
	make -C libft/ clean
	/bin/rm -f $(BINS)

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all

f: all
	./$(NAME) res/test.map

r: re f
