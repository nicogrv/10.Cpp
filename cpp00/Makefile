SRCS = ex00.cpp

OBJS = ${SRCS:.c=.o}

CC = c++

CFLAGS = -Wall -Werror -Wextra -I ./

NAME = megaphone

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all: 	${NAME}

clean:	
		rm -f ${OBJS}

fclean:	clean;
		rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re