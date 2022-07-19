#include "scaner.h"
#include "syntax.h"
#include "minishell.h"

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

void free_token(t_token *tk)
{
    if (tk->text)
        free(tk->text);
    free(tk);
}

t_token *tokenise(t_source *src)
{
    int     loop;
    char    ch;
    t_token *tk;
    char    *error;

    loop = 0;
    error = "error: failed to alloc buffer: ";
    if (!src || !src->string || !src->s_len)
    {
        errno = ENODATA;
        return &eof_token;
    }
    if (!tok_buf)
    {
        tok_bufsize = 1024;
        tok_buf = malloc(sizeof(tok_bufsize));
        if (!tok_buf)
        {
            errno = ENOMEM;
            return &eof_token;
        }
    }

    tok_bufindex = 0;
    tok_buf[0] = '\0';
    ch = next_char(src);

    if (ch == ERRCHAR || ch == EOF)
        return &eof_token;
    while ((ch = next_char(src)) != EOF)
    {
        if (ch == ' ')
            continue;
        else if (ch == '\t')
        {
            if (tok_bufindex > 0)
                loop = 1;
        }
        else if (ch == '\n')
        {
            if (tok_bufindex > 0)
                unget_char(src);
            else
                add_to_string(ch);
            loop = 1;
        }
        else
            add_to_string(ch);
        if (loop)
            break;
    }
    if (tok_bufindex == 0)
        return &eof_token;
    if (tok_bufindex >= tok_bufsize)
        tok_bufindex--;
    tok_buf[tok_bufindex] = '\0';
    tk = create_token(tok_buf);
    if (!tk)
    {
        error = ft_strjoin(error, strerror(errno));
        write(stderr, error, ft_strlen(error));
        return &eof_token;
    }
    tk->src = src;
    return tk;
}