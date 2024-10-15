NAME	:= philo

CFLAGS	:= -Wextra -Wall -Werror -pthread -g3

HEADERS	:= -Iinclude

SRCS	:= 	src/philo.c \
			src/init.c \
			src/print.c \
			src/free.c \
			src/list_init.c \
			src/list_utils.c

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