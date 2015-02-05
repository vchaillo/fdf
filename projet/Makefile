# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/27 19:25:58 by vchaillo          #+#    #+#              #
#    Updated: 2015/02/04 17:40:49 by valentin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS_NAME = main.c\
		   	mlx.c\
		   	parser.c\
		   	draw.c\
		   	lines.c\
		   	utils.c\
			error_msg.c\
			colors.c\
			color_mode.c\

SRCS_PATH = ./srcs/

OBJS_NAME = $(SRCS_NAME:.c=.o)

OBJS_PATH = ./objs/

SRCS = $(addprefix $(SRCS_PATH),$(SRCS_NAME))

OBJS = $(addprefix $(OBJS_PATH),$(OBJS_NAME))

FLAGS = -Wall -Wextra -Werror

LIBFT = -Llibft -lft

LIBFT_H = -I libft/includes/

FDF_H = -I includes/

LIB_MLX = -L/usr/X11/lib -lmlx -lXext -lX11

all: $(NAME)

$(NAME):
	@make -C libft/ fclean
	@make -C libft/
	@gcc $(FLAGS) $(LIBFT_H) $(FDF_H) -c $(SRCS)
	@mkdir $(OBJS_PATH)
	@mv $(OBJS_NAME) $(OBJS_PATH)
	@gcc -o $(NAME) $(OBJS) $(LIBFT) $(LIB_MLX)
	@echo "\033[32mfdf was created\033[0m"

norm:
	@echo "\033[32mnorminette...\033[0m"
	@norminette **/*.[ch]

clean:
	@rm -rf $(OBJS_PATH)
	@echo "\033[31mSuppression des .o\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[31mSuppression de fdf\033[0m"

re: fclean all

.PHONY: all norm clean fclean re
