make -C libft/ fclean
make -C libft/
gcc -Wall -Wextra -Werror -I libft/includes/ -I includes/ -c srcs/main.c srcs/mlx.c srcs/parser.c srcs/draw.c srcs/error_msg.c srcs/utils.c
gcc -o fdf main.o mlx.o parser.o draw.o error_msg.o utils.o -Llibft -lft  -L/usr/X11/lib -lmlx -lXext -lX11
rm *.o
echo "\033[32mfdf was created\033[0m"
