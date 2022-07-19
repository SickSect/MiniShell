NAME		=	minishell

CC			=	clang
FLAGS		=   -O0 -g -I inc/
HEADER		=	minishell.h
SRC			=	main.c syntax.c scanner.c node.c parser.c\
				utils/get_next_line.c utils/get_next_line_utils.c utils/prompt.c utils/atoi.c utils/get_next_line.c utils/get_next_line.c utils/isdigit.c utils/putchar.c utils/strcmp.c utils/strdup.c utils/strjoin.c utils/strlcpy.c utils/strlen.c

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