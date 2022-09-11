#ifndef PIPE_H
# define PIPE_H

# include "../inc/parser.h"
# include <sys/wait.h>
# include <sys/types.h>

typedef struct s_list
{
	char			*content;
	char			**cmd;
	struct s_list	*next;
}					t_list;

typedef struct s_cmd
{
	t_list	*lst;
	char	**mypaths;
	char	*cmd_path;
	int		in;
	int		out;
}				t_cmd;

typedef struct s_proccess
{
	int		fds[2];
	int		fdin;
	int		fdout;
}				t_proccess;

#endif