CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS_SERVER = server_bonus.c helpers_bonus.c
SRCS_CLIENT = client_bonus.c helpers_client_bonus.c
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
NAME_CLIENT = client
NAME_SERVER = server

all: $(NAME_CLIENT) $(NAME_SERVER)

bonus: all

$(NAME_SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJS_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJS_CLIENT)

%.o: %.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)

fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all
