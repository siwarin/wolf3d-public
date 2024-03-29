# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siwarin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/22 13:09:27 by siwarin           #+#    #+#              #
#    Updated: 2019/10/18 10:35:12 by cduverge         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

CFLAGS = -Wall -Wextra -Werror -O3 -flto

CC = gcc

HEADER = includes/Wolf.h

LIBFT = libft

LIB = libft/libft.a

INCL = /usr/local/include

SRCS = srcs/main.c srcs/parsing.c srcs/parsing_2.c srcs/textures.c srcs/commands.c srcs/commands2.c srcs/usefull.c srcs/graphics.c srcs/graphics2.c srcs/graphics3.c srcs/drawer.c srcs/help.c srcs/minimap.c libft/libft.a

OBJS = $(SRCS:.c=.o)

FRAM = -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(SRCS) $(LIB)
				$(CC) $(CFLAGS) -o $@ -I $(INCL) $(SRCS) $(LIB) -L /usr/local/lib -lmlx $(FRAM)

$(LIB) : force
		@make -C libft/

force :
		@true

clean :
		rm -f $(OBJS)
		@(cd $(LIBFT) && $(MAKE) $@)

fclean: clean
		rm -f $(NAME)

re: fclean all
