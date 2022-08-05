#include "minishell.h"
#include "executor.h"

void    FileNotFoundInPath(char *p, char *p2)
{
    p = p2;
	if (*p2 == ':')
		p++;
}