NAME		=	minishell

CC			=	clang
FLAGS		=   -O0 -g -I inc/
HEADER		=	inc/minishell.h inc/structures.h 
SRC			=	main.c \
				lib_utils/atoi.c lib_utils/get_next_line.c lib_utils/get_next_line_utils.c \
				lib_utils/isalnum.c lib_utils/isdigit.c lib_utils/putchar.c lib_utils/split.c \
				lib_utils/strcat.c lib_utils/strcmp.c lib_utils/strjoin.c lib_utils/strdup.c \
				lib_utils/ strlcpy.c lib_utils/strlen.c lib_utils/strncpy.c   
OBJ			=	$(SRC:.c=.o)

RM		=	rm -rf

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) -o $(NAME) $^

%.o:	%.c
			@$(CC) $(FLAGS) -o $@ -c $<

clean:
			@$(RM) $(OBJ) $(OBJ_BONUS)

fclean:		clean
			@$(RM) $(NAME) $(NAME_BONUS)

re:			fclean all

.PHONY:		all clean fclean re