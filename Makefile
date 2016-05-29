# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/27 19:25:58 by vchaillo          #+#    #+#              #
#    Updated: 2015/03/22 08:30:11 by vchaillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC	=	gcc
CFLAGS	+=	-Wall -Wextra -Werror
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

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	LIBMLX	=	-Lminilibx -lmlx -L/usr/lib -lXext -lX11 -lm
else
	UNAME_S = MACOS
	LIBMLX		=	-Lminilibx_macos/ -lmlx -framework OpenGL -framework AppKit
	FILE := $(shell ls libft/libft.a)
endif

LIBFT =	 -Llibft/ -lft

INC	=	-I inc/ -I minilibx/ -I libft/include/

OBJ	=	$(patsubst %.c, obj/%.o, $(SRC))


all:   $(NAME)
$(NAME): obj $(OBJ)
		
ifneq ($(FILE), libft/libft.a)
	@make -C libft/
endif
	
		@echo "[\033[1;32m******  Creating $(UNAME_S) executable  ******\033[m]"
		@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBMLX) $(LIBFT)

obj/%.o: src/%.c
		@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
		@echo "[\033[1;32m√\033[m]" $<

obj:
		@mkdir -p obj

clean:
		@echo "[\033[31;1m******  Cleaning object files  ******\033[0m]"
		@$(RM) obj/

fclean:	clean
		@echo "[\033[31;1m******  Cleaning executables  ******\033[0m]"
		@$(RM) $(NAME)

norm:
		@echo "[\033[1;32m******  norminette ...  ******\033[0m]"
		@norminette **/*.[ch]

re: fclean all

.PHONY: all obj clean fclean norm re
