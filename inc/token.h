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

extern t_token eof_t;
t_token	*tokenize(t_src *src);
void	t_free(t_token *t);

#endif