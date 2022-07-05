#include "minishell.h"

void print_prompt1(void)
{
    write (1, "$ ", 2);
   //fprintf(stderr, "$ ");
}

void print_prompt2(void)
{
     write (1, "> ", 2);
   //fprintf(stderr, "> ");
} 