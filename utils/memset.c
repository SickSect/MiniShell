#include "minishell.h"

void    *ft_memset(void *dest, int ch, size_t size)
{
    size_t i;

    i = 0;
    while (i < size)
    {
        dest[i] = ch;
        i++;
    }
    return (dest);
}