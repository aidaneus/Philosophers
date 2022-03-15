NAME = philo

CFLAGS			= -Wall -Wextra -Werror
LIBS			= -pthread
SRCS = main.c \
		ft_init.c \
		ft_death.c \
		ft_utils.c \
		ft_forks.c
OBJS = $(SRCS:.c=.o)
all: $(NAME)

$(NAME):		$(OBJS)
				gcc ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS}

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all