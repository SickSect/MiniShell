#include <stdlib.h>
#include <errno.h>
#include "minishell.h"
#include "src.h"
#include "token.h"

t_global *gb;

void init_global()
{
    gb->tb_size = 0;
    gb->tb_index = -1;
    gb->t_buf = NULL;
}

t_token eof_token = 
{
    .t_len = 0;
}

void b_adder(cgar ch)
{
    char    *tmp;

    gb->t_buf[gb->tb_index] = ch;
    if (gb->tb_index >= gb->tb_size)
    {
        tmp = ft_realloc(gb->t_buf, gb->tb_size * 2);
        if (!tmp)
        {
            errno (ENOMEM);
            return ;
        }
        gb->t_buf = tmp;
        gb->tb_size *= 2;
    }
}

t_token *t_create(char *str)
{
    t_token *t;

    t = malloc(sizeof(t_token));
    if (!t)
        return (NULL);
    
}
