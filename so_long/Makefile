CC = gcc
CFLAGS = -Wall -Wextra -Werror
FRAMEWORKS = -framework OpenGL -framework AppKit
NAME = so_long
SRC = src/bfs_ghosts.c \
	  src/events.c \
	  src/events2.c \
	  src/ghosts.c \
	  src/ghosts_assets.c \
	  src/gui.c \
	  src/gui_helper.c \
	  src/helpers1.c \
	  src/helpers2.c \
	  src/main.c \
	  src/map.c \
	  src/map2.c \
	  src/queue.c \

OBJ = $(SRC:.c=.o)
HEADER = include/so_long.h

GNL_SRCS = gnl/get_next_line.c gnl/get_next_line_utils.c
GNL_OBJS = $(GNL_SRCS:.c=.o)
GNL_HEADER = gnl/get_next_line.h

LIBFT = libft/libft.a

all: $(NAME)

bonus: all

$(NAME): $(OBJ) $(GNL_OBJS) $(LIBFT)
	$(CC) $(OBJ) $(GNL_OBJS) -Lmlx -lmlx -Llibft -lft $(FRAMEWORKS) -o $(NAME)

$(LIBFT):
	make -C libft bonus

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(OBJ): %.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(GNL_OBJS): %.o: %.c $(GNL_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C libft clean
	rm -f $(OBJ) $(GNL_OBJS)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all
