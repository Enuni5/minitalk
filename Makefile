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

all: ${NAME_SERVER} ${NAME_CLIENT}

$(NAME_SERVER): ${OBJS_SERVER}
	${MAKE} -C ./libft
	${CC} ${OBJS_SERVER} ${LIBRARY} -o ${NAME_SERVER}

$(NAME_CLIENT): ${OBJS_CLIENT}
	${MAKE} -C ./libft 
	${CC} ${OBJS_CLIENT} ${LIBRARY} -o ${NAME_CLIENT}

clean:
	${MAKE} -C ./libft clean 
	${RM} ${OBJS_SERVER} ${OBJS_CLIENT} 

fclean: clean
	${MAKE} -C ./libft fclean 
	${RM} ${NAME_CLIENT}
	${RM} ${NAME_SERVER}

re: fclean all

.PHONY: all clean fclean re bonus