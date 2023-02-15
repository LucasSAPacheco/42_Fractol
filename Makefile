
NAME	=	fractol

# MY LIBRARIES - libft.a and libftprintf.a
PRINTF_PATH =	./mylibs/
LIBFT_PATH =	./mylibs/libft/

PRINTF =		${PRINTF_PATH}libftprintf.a
LIBFT =			${LIBFT_PATH}libft.a

# INPUTS
SRC		=	main.c \
			./srcs/actions.c \
			./srcs/events.c \
			./srcs/fractal.c \
			./srcs/colors.c \
			./srcs/check_errors.c
	

HSRC	=	fractol.h 
OBJS	=	${SRC:.c=.o}

# compilation
CC		=	cc
CFLAGS	=	-g3 -O3
IMLX	=	-Imlx -Lmlx -lmlx -lXext -lX11 -lm

# clean
RM		=	rm -f

all: 		${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I.

${PRINTF}:
			make -C ${PRINTF_PATH}

${LIBFT}:
			make -C ${LIBFT_PATH}
			make bonus -C ${LIBFT_PATH}
			
${NAME}:	${OBJS} ${HSRC} ${PRINTF}
			ar -rcs fractol.a ${OBJS}
			${CC} ${CFLAGS} ${SRC} fractol.a ${PRINTF} ${IMLX} -o fractol

clean:
	rm -f ${OBJS}
	make clean -C ./mylibs/
	rm -f .srcs/${OBJS}

fclean:    clean
		rm -f fractol.a
		rm -f ${LIBFT}
		rm -f ${PRINTF}
		rm -f ${NAME}

re:		fclean all



.PHONY:    all clean fclean re