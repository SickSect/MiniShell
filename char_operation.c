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

void add_char(char *scan_str, char ch, int *current_index, int *current_size)
{
    char *new_scan_str;

    scan_str[*current_index++] = ch;
    if (*current_index >= *current_size)
    {
        new_scan_str = malloc(sizeof(char) * (*current_size * 2));
        if (!new_scan_str)
        {
            errno = ENOMEM;
            return ;
        }
        while (*scan_str)
        {
            *new_scan_str = *scan_str;
            scan_str++;
            new_scan_str++;
        }
        free(scan_str);
        scan_str = new_scan_str;
        *current_size *= 2;
    }
}