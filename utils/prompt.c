#include "minishell.h"

void display_prompt1(void)
{
    write (1, "$ ", 2);
}

void display_prompt2(void)
{
     write (1, "> ", 2);
} 