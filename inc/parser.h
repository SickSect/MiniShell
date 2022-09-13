#ifndef PARSER_H
# define PARSER_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include "minishell.h"

# define MINISHELL "\033[1;33m"
# define TEXT "\033[1;37m"
# define ERROR "\033[1;31m"

typedef struct s_lst
{
	char			*var;
	struct s_lst	*next;
}				t_lst;

typedef struct s_pre
{
	int	gap;
	int	gap2;
	int	pipes;
}				t_pre;

typedef struct s_inside_gap2
{
	char	in_redirect; // (<)
	char	out_redirect; // (>)
	char	pipe; // (|)
	char	cmd_separator; // бывшая point_coma (;)
	char	tilda; // (~)
	char	gap; // (\')  про эту херь не очень понятно
}				t_inside_gap_2;

// тут про эти символы, и более правильные названия, я их оттуда и взяла 
// https://www.howtogeek.com/439199/15-special-characters-you-need-to-know-for-bash/ 

#endif