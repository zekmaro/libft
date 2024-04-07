NAME := libft.a
CFLAGS := -Wall -Wextra -Werror
SRC := ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_striteri.c ft_strmapi.c ft_itoa.c ft_split.c ft_strtrim.c ft_strjoin.c ft_substr.c ft_toupper.c ft_strdup.c ft_calloc.c ft_atoi.c ft_strnstr.c ft_bzero.c ft_isalnum.c ft_isalpha.c	ft_isdigit.c ft_isprint.c ft_memcpy.c ft_memset.c  ft_strlen.c ft_isascii.c ft_strlcpy.c ft_memmove.c ft_strlcat.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c 
OBJ := $(SRC:%.c=%.o)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	cc $(CFLAGS) -c -o $@ $^

all: $(NAME) clean

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

so: $(OBJ)
	cc -shared -o libft.so $(OBJ)

.PHONY: all clean fclean re
