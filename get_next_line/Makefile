SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
HEADER = get_next_line.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libgnl.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
