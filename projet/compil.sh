gcc -Wall -Wextra -Werror -I libft/includes/ -c main.c mlx.c parser.c draw.c error_msg.c utils.c
gcc -o mlx_prog main.o mlx.o parser.o draw.o error_msg.o utils.o -Llibft -lft  -L/usr/X11/lib -lmlx -lXext -lX11
rm *.o
echo "\033[32mmlx_prog was created\033[0m"
