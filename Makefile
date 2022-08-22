SRC_SERVER = ./src/server.c

SRC_CLIENT = ./src/client.c

OBJS_SERVER = ${SRC_SERVER:.c=.o}

OBJS_CLIENT = ${SRC_CLIENT:.c=.o}

NAME_SERVER = server

NAME_CLIENT = client

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS_SERVER} ${OBJS_CLIENT}
	${MAKE} -C ./libft 
	${CC} ${NAME_SERVER} ${OBJS}
	${CC} ${NAME_CLIENT} ${OBJS}

all: ${NAME}

clean:
	${MAKE} -C ./libft clean 
	${RM} ${OBJS_SERVER} ${OBJS_CLIENT} 

fclean: clean
	${MAKE} -C ./libft fclean 
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus