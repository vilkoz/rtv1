# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrybalko <vrybalko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/23 14:08:11 by vrybalko          #+#    #+#              #
#    Updated: 2017/05/30 17:46:42 by vrybalko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1

IDIR = includes/

VPATH = src:includes

BIN_DIR = bin/

FLAGS = -Wall -Wextra -Werror -I$(IDIR) -g

UNAME_S = $(shell uname -s)

LIB = libft/libft.a

ifeq ($(UNAME_S),Darwin)
	FLAGS_MLX = -lmlx -framework OpenGl -framework AppKit -Lminilibx_macos/
	MLX_DIR = minilibx_macos
	LIB += $(MLX_DIR)/libmlx.a
endif
ifeq ($(UNAME_S),Linux)
	FLAGS_MLX = -lmlx -lXext -lX11 -lm -Lminilibx/
	MLX_DIR = minilibx
	LIB += $(MLX_DIR)/libmlx.a
endif

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

makelib:
	make -C libft/
	make -C $(MLX_DIR)

$(NAME): $(BINS) makelib
	gcc -o $(NAME) $(BINS) $(FLAGS) $(FLAGS_MLX) $(LIB)

$(BIN_DIR)%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

clean:
	make -C libft/ clean
	make -C $(MLX_DIR) clean
	/bin/rm -f $(BINS)

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
