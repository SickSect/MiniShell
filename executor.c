#include "minishell.h"
#include "executor.h"
#include "node.h"

char    search_path(char *file)
{
    char *PATH = getenv("PATH");
    char *p = PATH;
    char *p2;

    while (p && *p)
    {
        p2 = p;
        while (*p2 && *p2 != ':')
            p2++;
        int p_len = p2 - p;
        if (!p_len)
            p_len = 1;
        int a_len = ft_strlen(file);
        char path[p_len + 1 + a_len + 1];
        ft_strlcpy(path, p, p2 - p);
        path[p2 - p] = '\0';
        if (p2[-1] != '/')
    }
}