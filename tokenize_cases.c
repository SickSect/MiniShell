#include "minishell.h"
#include "token.h"
#include "parser.h"

int quote_case(t_scan_str *scan, t_source *src)
{
    int i;

    add_char(scan->current_char, scan);
    i = find_closing_quote(scan->scan_str + src->current_position);
    if (!i)
    {
        src->current_position = src->str_len;
        //error printing
        return (-1);
    }
    while (i--)
        add_char(get_next_char(src), scan);
    return (0);
}

int brace_case(t_scan_str *scan, t_source *src)
{
    scan->next_char = get_next_char(src);
    if (scan->next_char == '\n')
        return (0);
    add_char(scan->current_char, scan);
    if (scan->next_char > 0)
        add_char(scan->next_char, scan);
    return (0);
}

int dollar_case(t_scan_str *scan, t_source *src)
{
    int i;

    add_char(scan->current_char, scan);
    scan->current_char = peek_char(src);
    if (scan->current_char == '{' || scan->current_char == '(')
    {
        i = find_closing_quote(scan->scan_str + src->current_position + 1);
        if (!i)
        {
            src->current_position = src->str_len;
            // error printing
            return (-1);
        }
        while (i--)
            add_char(get_next_char(src), scan);
    }
    else if (ft_isalnum(scan->current_char) || scan->current_char == '*' 
            || scan->current_char == '@' || scan->current_char == '#' 
            || scan->current_char == '!' || scan->current_char == '?'
            || scan->current_char == '$')
            add_char(get_next_char(src), scan);
    return (0);
}

int void_case(t_scan_str *scan, t_source *src)
{
    if (scan->current_char == ' ' || scan->current_char == '\t')
    {
        if (src->current_position > src->str_len)
            return (-1);
    }
    else if (scan->current_char == '\n')
    {
        if (src->current_position > 0)
            char_back(src);
        else
            add_char(scan->current_char, scan);
    }
    return (-1);
}
