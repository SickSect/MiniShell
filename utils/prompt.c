#include "minishell.h"

void DisplayPrompt1(void)
{
    write (1, "$ ", 2);
}

void DisplayPrompt2(void)
{
     write (1, "> ", 2);
} 