NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

FT_PRINTF_SRC = ft_int_to_hex.c \
	ft_printf.c \
	get_format_type.c \
	bonus_init.c \
	bonus_char_str.c \
	bonus_helpers.c \
	bonus_helpers2.c \
	bonus_hex.c \
	bonus_ptr.c \
	bonus_int.c \
	bonus_unigned.c \
	bonus_percent.c \
	ft_itoi_unigned.c

LIBFT_SRC = \
	libft/ft_isalpha.c libft/ft_isdigit.c libft/ft_isalnum.c libft/ft_isascii.c libft/ft_isprint.c \
	libft/ft_strlen.c libft/ft_memset.c libft/ft_bzero.c libft/ft_memcpy.c libft/ft_memcpy.c libft/ft_memmove.c \
	libft/ft_strlcpy.c libft/ft_strlcat.c libft/ft_toupper.c libft/ft_tolower.c libft/ft_strchr.c \
	libft/ft_strrchr.c libft/ft_strncmp.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_strnstr.c libft/ft_atoi.c \
	libft/ft_calloc.c libft/ft_strdup.c libft/ft_substr.c libft/ft_strjoin.c libft/ft_strtrim.c libft/ft_split.c \
	libft/ft_itoa.c libft/ft_strmapi.c libft/ft_striteri.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c \
	libft/ft_putendl_fd.c libft/ft_putnbr_fd.c

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

FT_PRINTF_OBJS = $(FT_PRINTF_SRC:.c=.o)

HEADER = ft_printf.h
LIBFT_HEADER = $(LIBFT_DIR)/libft.h

all: $(NAME)

bonus: all

$(NAME): $(FT_PRINTF_OBJS) $(LIBFT_LIB)
	cp $(LIBFT_LIB) $(NAME)
	ar rcs $(NAME) $(FT_PRINTF_OBJS)

%.o: %.c $(HEADER) $(LIBFT_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_LIB): $(LIBFT_SRC) $(LIBFT_HEADER)
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(FT_PRINTF_OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

test: all
	$(CC) main.c -L. -lftprintf -o test

.PHONY: all clean fclean re test bonus
