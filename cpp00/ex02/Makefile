SRCS = tests.cpp Account.cpp

OBJS = ${SRCS:.c=.o}

CC = c++

CFLAGS = -g -Wall -Werror -Wextra -I ./

NAME = phonebook

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} Makefile Account.hpp
		${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all: 	${NAME}

clean:	
		rm -f ${OBJS}

fclean:	clean;
		rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re