#include "minishell.h"
#include "executor.h"
#include "node.h"

char    search_path(char *file)
{
    char *PATH = getenv("PATH");
    char *p = PATH;
    char *p2;
    struct stat st;

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
            strcat(path, "/");
        strcat(path, file);
        if (stat(path, &st) == 0)
        {
            if(!S_ISREG(st.st_mode))
            {
                errno = ENOENT;
                p = p2;
                if (*p2 == ':')
                    p++;
                continue;
            }
            p = malloc(ft_strlen(path) + 1);
            if (!p)
                return (NULL);
            strcpy(p, path);
            return (p);
        }
        else
            p = p2;
            if (*p2 == ':')
                p++;
    }
    errno = ENOENT;
    return (NULL);
}

int do_exec_cmd(int argc, char **argv)
{
    char	*path;

    if (ft_strchr(argv[0], '/'))
        execv(argv[0], '/');
    else
    {
		path = search_path(argv[0]);
		if (!path)
			return (0);
		execv(path, argv);
		free(path);
    }
	return (0);
}

static inline void free_argv(int argc, char **argv)
{
	if (!argc)
		return ;
	while (argc--)
		free(argv[argc]);
}

int	do_simple_command(t_node *node)
{
	t_node	*child;
	int		argc;
	long	max_args;
	char	*str;
	pid_t	child_pid;
	int		status;

	if (!node)
		return (0);
	child = node->first_child;
	if (!child)
		return (0);
	argc = 0;
	max_args = 255;
	char 	*argv[max_args + 1];
	while (child)
	{
		str = child->val.str;
		argv[argc] = malloc(strlen(str) + 1);
		if (!argv[argc])
		{
			free_argv(argc, argv);
			return (0);
		}
		strcpy(argv[argc], str);
		if (++argc >= max_args)
			break;
		child = child->next_sibling;
	}
	argv[argc] = NULL;
	child_pid = 0;
	if ((child_pid = fork()) == 0)
	{
		do_exec_cmd(argc, argv);
		write(stderr, "error: failed to execute command: ", 34);
		write(stderr, strerror(errno), ft_strlen(strerror(errno)));
		if (errno = ENOEXEC)
			exit(126);
		else if (errno == ENOENT)
			exit (127);
		else
			exit (EXIT_FAILURE);
	}
	else if(child_pid < 0)
	{
		write(stderr, "error: failed to execute command: ", 34);
		write(stderr, strerror(errno), ft_strlen(strerror(errno)));
		return (0);
	}
	status = 0;
	waitpid(child_pid, &status, 0);
	free(argc, argv);
}