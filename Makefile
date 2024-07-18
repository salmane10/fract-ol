NAME	= fractol
CC	= cc
CFLAGS	= -Wall -Wextra -Werror
SRC	= main.c render.c init.c events.c math.c utils.c
OBJ	= $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -Lminilibx-linux -lmlx_Linux -lX11 -lXext -o  $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
