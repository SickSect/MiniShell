#include "minishell.h"
#include "parser.h"
#include "test.h"

void print_str(char **str)
{
    int i = 0;

    while (str[i] != NULL)
    {
        printf(" ARG%d: |%s| ", i, str[i]);
        i++;
    }
}