SRC_SERVER = ./src/server.c

SRC_CLIENT = ./src/client.c

OBJS_SERVER = ${SRC_SERVER:.c=.o}

OBJS_CLIENT = ${SRC_CLIENT:.c=.o}

NAME_SERVER = server

NAME_CLIENT = client

LIBRARY = libft/libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:  norminette libft compile

norminette: 
	@echo "\n *** CHECKING 42 NORMINETTE ***\n"
	@norminette src/

libft: 
	@echo "\n *** COMPILING LIBFT ***\n"
	${MAKE} -C ./libft --silent

compile: ${NAME_SERVER} ${NAME_CLIENT}

$(NAME_SERVER): ${OBJS_SERVER}
	@echo "\n *** COMPILING SERVER PROGRAM ***\n"
	${CC} ${OBJS_SERVER} ${LIBRARY} -o ${NAME_SERVER}

$(NAME_CLIENT): ${OBJS_CLIENT}
	@echo "\n *** COMPILING CLIENT PROGRAM ***\n"
	${CC} ${OBJS_CLIENT} ${LIBRARY} -o ${NAME_CLIENT}

clean:
	${MAKE} -C ./libft clean --silent
	${RM} ${OBJS_SERVER} ${OBJS_CLIENT} 


fclean: clean
	${MAKE} -C ./libft fclean --silent
	${RM} ${NAME_CLIENT}
	${RM} ${NAME_SERVER}

re: fclean all

.PHONY: all clean fclean re libft compile norminette