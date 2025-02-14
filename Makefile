CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC = main.c checks.c command.c stack_util.c sort.c
OBJECTS = $(SRC:.c=.o)
LIBFT = ./libft
NAME = push_swap

all:$(NAME)

$(NAME): $(OBJECTS) $(LIBFT)/libft.a
	$(CC) $(CFLAGS) $(OBJECTS) -L$(LIBFT) -lft -o $(NAME)

$(LIBFT)/libft.a:
	@make -C $(LIBFT)

clean : 
	rm -f $(OBJECTS)
	@make clean -C $(LIBFT)

fclean : clean
	rm -f $(NAME)
	@make fclean -C $(LIBFT)

re : fclean all

.PHONY: all clean fclean re 