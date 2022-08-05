#include "minishell.h"
#include "executor.h"

int DoExecCommand(int argc, char **argv)
{
    char *path;

    if (ft_strchr(argv[0], '/'))
        execv(argv[0], argv);
    else
    {
        path = SearchPath(argv[0]);
        if (!path)
            return 0;
        execv(path, argv);
        free(path);
    }
    return 0;
}