SRCS_MAIN	= main.c \
		  utils.c \
		  map.c \
		  line.c \
		  swap_arr.c

OBJS_MAIN	= ${addprefix srcs/, ${SRCS_MAIN:.c=.o}}

NAME_MAIN	= fdf

CC		= cc -Wall -Wextra -Werror

FLAGS		= -lXext -lX11 -lm

RM		= rm -f

LIBFT		= inc/libft/libft.a

GNL		= inc/get_next_line/get_next_line.c \
		  inc/get_next_line/get_next_line_utils.c

PATH_LIBFT	= -C inc/libft

MINILIBX	= inc/minilibx-linux/libmlx.a

PATH_MINILIBX	= -C inc/minilibx-linux

.c.o:
		${CC} -c $< -o ${<:.c=.o}

all:		${NAME_MAIN}

${NAME_MAIN}:	${OBJS_MAIN}
		${MAKE} ${PATH_LIBFT}
		${MAKE} ${PATH_MINILIBX}
		${CC} ${OBJS_MAIN} ${LIBFT} ${GNL} ${MINILIBX} ${FLAGS} -o ${NAME_MAIN}

clean:
		${RM} ${OBJS_MAIN}
		${MAKE} clean ${PATH_LIBFT}
		${MAKE} clean ${PATH_MINILIBX}

fclean:		clean
		${RM} ${NAME_MAIN}
		${MAKE} fclean ${PATH_LIBFT}

re:		fclean all

.PHONY:		all clean fclean re
