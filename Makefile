MAKEFLAGS	= --no-print-directory --silent
NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3 #quitar g3 al entregar
RM = rm -rf

INCLUDE = -I libs/MLX42/include -I libs/libft -I.

MLXFLAGS = libs/MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm

SRC = fdf.c ft_atoi_hexa.c parsing.c bresenham.c\

OBJ = $(SRC:.c=.o)

LIB = libs/libft/libft.a

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $^

all: libmlx $(NAME)

libmlx:
	cmake libs/MLX42 -B libs/MLX42/build && make -C libs/MLX42/build -j4

$(NAME): $(OBJ)
	make -C libs/libft
	$(CC) $(CFLAGS) $(OBJ) $(LIB) $(MLXFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJ)
	make clean -C libs/libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C libs/libft

re: fclean all

.PHONY: all clean fclean re libmlx