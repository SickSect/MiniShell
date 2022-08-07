#include "minishell.h"
#include "parser.h"
#include "test.h"

void check_argv(t_source *source)
{
    printf("LEN IS %zu main str is %s\n", source->str_len, source->buf_str);
    int i = 0;
    while (source->substr_arg[i])
    {
        printf("ARG %d - %s\n", i, source->substr_arg[i]);
        i++;
    }
}

void print_str(char **str)
{
    int i = 0;

    printf("PRINTING\n");
    while (str[i] != NULL)
    {
        printf(" %d = |%s|\n", i, str[i]);
        i++;
    }
    printf("ARG IN PIPE IS %d\n", i);
}