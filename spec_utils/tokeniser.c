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

t_token eof_t = 
{
    .t_len = 0,
};

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
    char    *n_str;

    t = malloc(sizeof(t_token));
    if (!t)
        return (NULL);
    gb->tb_size = ft_strlen(str);
    n_str = malloc(sizeof(char) * t->tb_size + 1);
    if (!n_str)
    {
        free (t);
        return (NULL);
    }
    ft_strcpy(n_str, str);
    gb->t_buf = n_str;
    gb->t = t;
    return (t);
}

void	t_free(t_token *t)
{
	if (t->text)
		free(t->text);
	free(t);
} 

static int pre_check(t_token *t)
{
    if (!t || !t->text || !t->t_len)
    {
        errno = ENODATA;
        return &eof_t;
    }
    if (!t->text)
    {
        gb->tb_size = 1024;
        gb->t_buf = malloc(gb->tb_size);
        if (!gb->t_buf)
        {
            errno = ENOMEM;
            return &eof_t;
        }
    }
    return (1);
}

t_token *make_token(t_src *t)
{
    int loop;
    char *n_ch;

    loop = 0;
    if (pre_check(t) != 1)
        return (NULL);
    gb->tb_index = 0;
    gb->t_buf[0] = '\0';
    n_ch = next_ch(t);
    if (n_ch == ERR_CH || n_ch == EOF)
        return &eof_t;
    while ((ch = next_ch(src)) != EOF)
    {
        if (ch == ' ')
            ;
        else if (ch == '\t')
        {
            if (gb->tb_index > 0)
                eof_t = 1;
        }
        else if (ch == '\n')
        {
            if (gb->tb_index > 0)
                unget_ch(t);
            else
                b_adder(ch);
                loop = 1;
        }
        else
            b_adder(ch);
        if (loop)   
            break;      
    }
    if (gb->tb_index == 0)
        return &eof_t;
    if (gb->tb_index >= gb->tb_size)
        gb->tb_index--;
    gb->t_buf[gb->tb_index] = '\0';
    t_token *st = t_create(gb->t_buf);
    if (!st)
    {
        
    }
}
