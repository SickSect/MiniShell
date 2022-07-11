#ifndef TOKEN_H
# define TOKEN_H

#include "src.h"
#include "minishell.h"

typedef struct s_token
{
    t_src	*src;
    int		t_len;
    char	*text;
}	t_token;

typedef struct s_need_to_be_global
{
	char	*t_buf;
    int		tb_size;
	int		tb_index;
    t_token *t;
}	t_global;

extern t_token eof_t;
t_token	*tokenize(t_src *src);
void	t_free(t_token *t);

#endif