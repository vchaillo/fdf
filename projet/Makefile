# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/27 19:25:58 by vchaillo          #+#    #+#              #
#    Updated: 2015/02/25 15:14:26 by vchaillo         ###   ########.fr        #
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
			projections.c\
			menus.c\
			moves.c\
			strings.c\
			key_hook.c\
			mouse_hook.c\
			rotations.c\

SRCS_PATH = ./srcs/

OBJS_NAME = $(SRCS_NAME:.c=.o)

OBJS_PATH = ./objs/

SRCS = $(addprefix $(SRCS_PATH),$(SRCS_NAME))

OBJS = $(addprefix $(OBJS_PATH),$(OBJS_NAME))

FLAGS = -Wall -Wextra -Werror

LIBFT_H = -I libft/includes/

LIBFT = -Llibft -lft

MLX_H = -I minilibx/

LIB_MLX = -Lminilibx -lmlx -framework OpenGl -framework Appkit

FDF_H = -I includes/

all: $(NAME)

$(NAME):
	@make -C libft/ fclean
	@make -C libft/
	@make -C minilibx/ clean
	@make -C minilibx/
	@gcc -g $(FLAGS) $(LIBFT_H) $(FDF_H) $(MLX_H) -c $(SRCS)
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
