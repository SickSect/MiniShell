#include "minishell.h"

char *ft_realloc(char *str, int size)
{
    char    *new_ptr;
    size_t  i;

    new_ptr = malloc(sizeof(char) * size + 1);
    i = 0;
    while(str[i++])
        new_ptr[i] = str[i];
}