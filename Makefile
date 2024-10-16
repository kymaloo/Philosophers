NAME	:= philo

CFLAGS	:= -Wextra -Wall -Werror -pthread -g3

HEADERS	:= -Iinclude

SRCS =	src/main.c \
		src/init.c \
		src/routine.c \
		src/eat.c \
		src/libft.c \
		src/utils.c \
		src/get_data.c \
		src/get_data2.c \
		src/get_philo.c \
		src/update_value.c

OBJS	:= ${SRCS:.c=.o}

all: $(NAME)

n:
	norminette src/ include/

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re