# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/27 19:25:58 by vchaillo          #+#    #+#              #
#    Updated: 2017/04/03 22:30:34 by vchaillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC	=	gcc
CFLAGS	=	-Wall -Wextra -Werror -O3
RM	=	rm -Rf

# Colors
GREY = \033[30;1m
RED = \033[31;1m
GREEN =	\033[32;1m
YELLOW = \033[33;1m
BLUE = \033[34;1m
WHITE = \033[37;1m
END_COLOR =	\033[0m

SRC = main.c\
	init.c\
	mlx.c\
	parser.c\
	draw.c\
	lines.c\
	errors.c\
	colors.c\
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
	LIBMLX		=	-Llib/mlx/minilibx_$(SYSTEM) -lmlx -framework OpenGL -framework AppKit
endif
LIBFT =	 -Llib/libft/ -lft
INC	=	-I inc/ -I lib/mlx/minilibx_$(SYSTEM) -I lib/libft/includes/
OBJ	=	$(patsubst %.c, obj/%.o, $(SRC))


all:   $(NAME)
$(NAME): obj libft $(OBJ)
		@echo "==========================="
		@printf "$(WHITE)Creating $(NAME)... $(END_COLOR)"
		@$(CC) -o $@ $(OBJ) $(LIBMLX) $(LIBFT)
		@echo "$(GREEN)Done √$(END_COLOR)"
		@echo "==========================="

DEPS := $(OBJ:.o=.d)
-include $(DEPS)
obj/%.o: src/%.c
		@$(CC) $(CFLAGS) -MD $(INC) -o $@ -c $<
		@echo "[$(GREEN)√$(END_COLOR)]" $<

obj:
		@mkdir -p obj

libft:
		@make -sC lib/libft/ 2>&-

clean:
		@echo "$(BLUE)$(NAME)$(GREY) - Cleaning object files$(END_COLOR)"
		@$(RM) obj/

fclean:	clean
		@echo "$(BLUE)$(NAME)$(GREY) - Cleaning executables$(END_COLOR)"
		@$(RM) $(NAME)
		@make -sC lib/libft/ fclean 2>&-

norm:
		@echo "$(BLUE)Norminette...$(END_COLOR)"
		@norminette src inc

re: fclean all

.PHONY: all obj libft clean fclean norm re
