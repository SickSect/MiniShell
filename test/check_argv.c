#include "minishell.h"
#include "parser.h"
#include "test.h"

void check_argv(t_source *source)
{
    int i = 0;
    while (source->substr_arg[i])
    {
        printf("all ARG %d - |%s|\n", i, source->substr_arg[i]);
        i++;
    }
}

void print_str(char **str)
{
    int i = 0;

    while (str[i] != NULL)
    {
        printf(" %d = |%s|\n", i, str[i]);
        i++;
    }
}