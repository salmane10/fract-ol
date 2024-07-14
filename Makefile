NAME	= fractol
CC	= cc
CFLAGS	= -Wall -Wextra -Werror
SRC	= main.c fractol.h render.c init.c math_utils.c fractol_utils.c

OBJ	= $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o  $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
