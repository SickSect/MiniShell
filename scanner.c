#include "scaner.h"

char *tok_buf = NULL;
int   tok_bufsize  = 0;
int   tok_bufindex = -1;

static char *memory_up(int size, char *orig)
{
    char    *new;
    size_t  i;

    i = 0;
    new = malloc(sizeof(char) * size + 1);
    if (!new)
    {
        errno = ENOMEM;
        return NULL;
    }
    while(orig[i])
    {
        new[i] = orig[i];
        i++;
    }
    new[i] = '\0';
    while (i < size)
        new[i++] = '\0';
    free(tok_buf);
    return (new);
}

struct token_s eof_token = 
{
	.text_len = 0,
};

void    add_to_string(char ch)
{
    char    *tmp;

    tok_buf[tok_bufindex++] = ch;
    if (tok_bufindex >= tok_bufsize)
    {
        tmp = memory_up(tok_bufsize * 2, tok_buf);
        if (!tmp)
        {
            errno = ENOMEM;
            return ;
        }
        tok_buf = tmp;
        tok_bufsize *= 2;
    }
}

t_token *create_token(char *str)
{
    t_token *tk;
    char    *new_str;

    tk = malloc(sizeof(t_token));
    if (!tk)
        return (NULL);
    tk->text = NULL;
    tk->text_len = ft_strlen(str);
    tk->src = NULL;
    new_str = malloc(sizeof(tk->text_len + 1));
    if (!new_str)
    {
        free(tk);
        return NULL;
    }
    ft_strcpy(new_str, str);
    tk->text = new_str;
    return (tk);
}