#include "minishell.h"
#include "parser.h"

int get_len_with_spaces(char *str)
{
    int i;
    int len;

    i = 0;
    len = 0;
    while (str[i])
    {
        if (str[i] == '|')
        {
            len++;
            if (str[i + 1] != ' ')
            {
                len++;
                i++;
            }
        }
        i++;
    }
    return (len + i);
}