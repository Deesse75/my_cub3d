NAME = libft.a
HEADER = ./
SRC = find_back_n.c  ft_atoi.c ft_itoa.c ft_strchr.c ft_strjoin.c ft_strlen.c\
	ft_strnstr.c ft_strtrim.c gnl.c free_strs.c ft_isalnum.c ft_split.c ft_strdup.c\
	ft_strlcpy.c ft_strncmp.c ft_strrchr.c ft_substr.c size_strs.c
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c 
	$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
