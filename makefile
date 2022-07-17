NAME		=	minishell

CC			=	clang
FLAGS		=   -O0 -g -I inc/
HEADER		=	minishell.h
SRC			=	main.c 

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