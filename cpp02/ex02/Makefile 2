SHELL = /bin/bash

SRCS += main.cpp
SRCS += Fixed.cpp

HPP += Fixed.hpp

OBJS = ${patsubst %.cpp, ${OBJS_PATH}/%.o, ${SRCS}}

SRC_PATH += ./src/
OBJS_PATH = ./src/_Objet
HEAD_PATH += -I ./Include


NAME = ex02
CC = c++
CFLAGS = -g -std=c++98 -Wall -Werror -Wextra -I ./

vpath %.cpp ${SRC_PATH}    
vpath %.hpp ${HEAD_PATH}

all: ${NAME}

${NAME}: ${OBJS}
	@ ${CC} -o ${NAME} ${OBJS} ${HEAD_PATH} ${CFLAGS}
	@ echo -ne "\r\033[2K" $(LIGHTGREEN) "\t$(NAME) OK" "\033[0m" "\n"

${OBJS_PATH}/%.o: %.cpp Makefile ${HPP}
	@ mkdir -p ${OBJS_PATH}
	@ $(COLORCOMPIL)
	@ ${CC} ${CFLAGS} -c $< -o $@ ${HEAD_PATH}

clean:
	@ echo -ne "\r\033[2K" $(YELLOW) "Cleaning\n\n"$(NC)
	@ rm -rf ${OBJS_PATH}

fclean: clean
	@ rm -f ${NAME}
	@ echo -ne "\r\033[2K" $(GREEN) "\t$(NAME) Remove\n"$(NC)"\n"

re: fclean
	@ echo -ne "\r\033[2K" $(YELLOW) "Rebuilding..."$(NC)"\n""\n"
	@ $(MAKE) -s

.PHONY: re clean fclean

NC='\033[0m'
RED='\033[0;31m'
GREEN='\033[0;32m'
ORANGE='\033[0;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
LIGHTGRAY='\033[0;37m'

DARKGRAY='\033[1;30m'
LIGHTRED='\033[1;31m'
LIGHTGREEN='\033[1;32m'
LIGHTBLUE='\033[1;34m'
LIGHTPURPLE='\033[1;35m'
LIGHTCYAN='\033[1;36m'
YELLOW='\033[1;33m'
WHITE='\033[1;37m'


ifndef COLORCOMPIL
COLORCOMPIL = \
	if [ "$(shell test $P -lt 33; echo $$?)" = "0" ]; then \
    	echo -ne "\r\033[2K" $(LIGHTRED) "[$(P)%] "$(DARKGRAY) "Compiling "$(NAME) $(WHITE) "$<"; \
	else \
		if [ "$(shell test $P -lt 66; echo $$?)" = "0" ]; then \
    		echo -ne "\r\033[2K" $(YELLOW) "[$(P)%]" $(DARKGRAY) "Compiling "$(NAME) $(WHITE) "$<"; \
		else \
       		echo -ne "\r\033[2K" $(LIGHTGREEN) "[$(P)%]" $(DARKGRAY) "Compiling "$(NAME) $(WHITE) "$<"; \
		fi \
	fi
T := $(words $(SRCS))
N := x
C = $(words $N)$(eval N := x $N)
P = `expr $C '*' 100 / $T / 5`
endif
