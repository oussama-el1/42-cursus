NAME = push_swap
BONUS_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = src/main.c \
      src/calls_op.c \
      src/calls_op2.c \
      src/helpers.c \
      src/operations.c \
      src/stack.c \
      src/parsing.c \
      src/validation.c \
      src/utils.c \
      src/pivot_sort.c \
      src/ft_split.c \
      src/ft_strlen.c

BONUS_SRC = Bonus/checker.c \
            Bonus/ft_strcmp.c \
            src/calls_op.c \
            src/calls_op2.c \
            src/helpers.c \
            src/operations.c \
            src/stack.c \
            src/parsing.c \
            src/validation.c \
            src/utils.c \
            src/ft_split.c \
            src/ft_strlen.c

GNL_SRCS = utils/get_next_line.c \
           utils/get_next_line_utils.c

HEADER = includes/push_swap.h
GNL_HEADER = utils/get_next_line.h
BONUS_HEADERS = $(HEADER) $(GNL_HEADER)

OBJ = $(SRC:.c=.o)
BONUS_OBJS = $(BONUS_SRC:.c=.o)
GNL_OBJS = $(GNL_SRCS:.c=.o)

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(GNL_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(GNL_OBJS) -o $(BONUS_NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(GNL_OBJS): %.o: %.c $(GNL_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJS): %.o: %.c $(BONUS_HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJS) $(GNL_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re
