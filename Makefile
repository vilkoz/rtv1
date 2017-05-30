# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrybalko <vrybalko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/23 14:08:11 by vrybalko          #+#    #+#              #
#    Updated: 2017/05/30 17:00:00 by vrybalko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1

IDIR = includes/

VPATH = src:includes

BIN_DIR = bin/

FLAGS = -Wall -Wextra -Werror -I$(IDIR) -g

UNAME_S = $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
	FLAGS_MLX = -lmlx -framework OpenGl -framework AppKit
endif
ifeq ($(UNAME_S),Linux)
	FLAGS_MLX = -lmlx -lXext -lX11 -lm
endif

LIB = libft/libft.a

SRCS = main.c			\
       ft_hooks.c		\
	   ft_img_px_put.c	\
	   ft_mlx_events.c	\
	   ft_mlx_init.c	\
	   ray_tools.c		\
	   render.c			\
	   scene.c			\
	   sphere.c			\
	   cylinder.c		\
	   cone.c			\
	   color.c			\
	   plane.c			\
	   matrix.c			\
	   read_file.c

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
