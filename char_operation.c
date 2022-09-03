#include "parser.h"
#include "minishell.h"
#include "token.h"

size_t  find_closing_quote(char *data)
{
    char    quote;
    size_t  i;
    size_t  len;

    i = 0;
    len = ft_strlen(data);
    quote = data[0];
    if (quote != '\'' && quote != '"' && quote != '`')
        return (0);
    while (++i < len)
    {
        if (data[i] == quote)
        {
            if (data[i - 1] == '\\')
            {
                if (quote != '\'')
                    continue;
            }
            return (i);
        }
    }
    return (0);
}

char    peek_char(t_source *src)
{
    long    pos;
    if (!src || !src->command)
    {
        errno = ENODATA;
        return (Error_char);
    }
    pos = src->current_position;
    if (pos == Init_position)
        pos++;
    pos++;
    if (pos >= src->str_len)
        return (End_of_file);
    return (src->command[pos]);
}

char    get_next_char(t_source *src)
{
    char    ch;

    if (!src || !src->command)
    {
        errno = ENODATA;
        return (Error_char);
    }
    ch = 0;
    if (src->current_position == Init_position)
        src->current_position = -1;
    else
        ch = src->command[src->current_position];
    if (++src->current_position >= src->str_len)
    {
        src->current_position = src->str_len;
        return (End_of_file);
    }
    return (src->command[src->current_position]);
}

void    char_back(t_source *src)
{
    if (src->current_position < 0)
        return ;
    src->current_position--;
}

void add_char(char ch, t_scan_str *scan)
{
    char    *tmp;

    scan->scan_str[scan->current_index++] = ch;
    if (scan->current_index >= scan->current_size)
    {
        tmp = malloc(sizeof(char) * (scan->current_size * 2));
        if (!tmp)
        {
            errno = ENOMEM;
            return ;
        }
        ft_strlcpy(tmp, scan->scan_str, scan->current_size);
        free(scan->scan_str);
        scan->scan_str = tmp;
        scan->current_size *= 2;
    }
}