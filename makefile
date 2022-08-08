NAME		=	minishell

CC			=	clang
FLAGS		=   -O0 -g -I inc/
HEADER		=	minishell.h parser.h test.h
SRC			=	main.c parser.c\
				utils/get_next_line.c utils/get_next_line_utils.c utils/memset.c\
				utils/atoi.c utils/strcmp.c utils/isdigit.c utils/prompt.c \
				utils/strlen.c utils/strdup.c utils/strjoin.c utils/realloc.c \
				utils/token_oper.c utils/strlcpy.c utils/split.c \
				test/check_argv.c
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