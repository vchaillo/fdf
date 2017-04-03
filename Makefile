# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/27 19:25:58 by vchaillo          #+#    #+#              #
#    Updated: 2017/04/03 02:21:54 by valentin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC	=	gcc
CFLAGS	=	-Wall -Wextra -Werror -O3
RM	=	rm -Rf

SRC = main.c\
	mlx.c\
	parser.c\
	draw.c\
	lines.c\
	utils.c\
	error_msg.c\
	colors.c\
	color_mode.c\
	projections.c\
	menus.c\
	moves.c\
	strings.c\
	key_hook.c\
	mouse_hook.c\
	rotations.c\

SYSTEM := $(shell uname -s)
ifeq ($(SYSTEM), Linux)
	LIBMLX	=	-Llib/mlx/minilibx_$(SYSTEM) -lmlx -L/usr/lib -lXext -lX11 -lm
else
	SYSTEM = MACOS
	LIBMLX		=	-Llib/mlxminilibx__$(SYSTEM) -lmlx -framework OpenGL -framework AppKit
	FILE := $(shell ls libft/libft.a)
endif
LIBFT =	 -Llib/libft/ -lft
INC	=	-I inc/ -I lib/mlx/minilibx_$(SYSTEM) -I lib/libft/include/
OBJ	=	$(patsubst %.c, obj/%.o, $(SRC))


all:   $(NAME)
$(NAME): obj libft $(OBJ)
		@echo "[\033[1;32m******  Creating $(SYSTEM) executable  ******\033[m]"
		@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBMLX) $(LIBFT)

obj/%.o: src/%.c
		@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
		@echo "[\033[1;32m√\033[m]" $<

obj:
		@mkdir -p obj

libft:
		@make -sC lib/libft/ 2>&-

clean:
		@echo "[\033[31;1m******  Cleaning object files  ******\033[0m]"
		@$(RM) obj/

fclean:	clean
		@echo "[\033[31;1m******  Cleaning executables  ******\033[0m]"
		@$(RM) $(NAME)
		@make -sC lib/libft/ fclean 2>&-

norm:
		@echo "[\033[1;32m******  norminette ...  ******\033[0m]"
		@norminette src inc

re: fclean all

.PHONY: all obj libft clean fclean norm re
