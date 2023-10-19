NAME = libftprintf.a

SRCS = *.c

# BSRCS =

OBJS = ${SRCS:.c=.o}

# BOBJ = ${BSRCS:.c=.o}

RM = rm -f

CC = gcc

FLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	ar -rcs ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS} ${BOBJ}

fclean:    clean
	${RM} ${NAME}

re: fclean all

bonus: ${BOBJ}
	ar -rcs ${NAME} ${BOBJ}

.PHONY: all bonus clean fclean re
