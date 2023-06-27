NAME = cub3d
INCLUDE = ./include
HEADER = ./include/cub3d.h ./include/cub3d_struct.h ./libft/libft.h
SRC = src/main.c src/check_argv.c\
	src/close/close_game.c\
	src/init/init.c src/init/init_game.c \
	src/parse/copy_file.c src/parse/parse_param.c src/parse/fill_color_param.c\
	src/parse/fill_texture_param.c src/parse/parse_map.c src/parse/check_map.c
OBJ = $(SRC:.c=.o)
LIB = ./libft/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
CMLX = -Iminilibx/ -Lminilibx/ -lmlx_Linux -lmlx -lXext -lX11

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	make -C minilibx/
	make -C libft/
	$(CC) $(CFLAGS) $(OBJ) $(LIB) $(CMLX) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

clean:
	make clean -C minilibx/
	make clean -C libft/
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re