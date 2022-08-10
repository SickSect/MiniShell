#include "minishell.h"
#include "parser.h"
#include "executor.h"

void    FileNotFoundInPath(char *p, char *p2)
{
    p = p2;
	if (*p2 == ':')
		p++;
}

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

static inline void FreeArgv(int argc, char **argv)
{
	if (!argc)
		return ;
	while (argc--)
		free(argv[argc]);
}

static int	PutValInStr(char *str, int argc, char *argv,t_node *child)
{
	while (child)
	{
		str = child->val.str;
		argv[argc] = malloc(sizeof(char) * (ft_strlen(str) + 1));
		if (!argv[argc])
		{
			FreeArgv(argc, argv);
			return (ErrMemoryArgv);
			ft_strcpy(argv[argc], str);
			if (++argc >= 255)
				break;
			child = child->next_sibling;
		}
	}
	return argc;
}

static void	StartFork(pid_t childPid, char **argv, int argc)
{
	if ((childPid = fork()) == 0)
	{
		DoExecCommand(argc, argv);
		write(stderr, "error: failed to execute command: ", 34);
		write(stderr, strerror(errno), ft_strlen(strerror(errno)));
		if (errno = ENOEXEC)
			exit (126);
		else if (errno = ENOENT)
			exit (127);
		else
			exit (EXIT_FAILURE);
	}
	else if (childPid < 0)
	{
		write(stderr, "error: failed to execute command: ", 34);
		write(stderr, strerror(errno), ft_strlen(strerror(errno)));
		return ;
	}
}

int do_simple_command(t_node *node, t_node *childFirst)
{
    //t_node	*child;
	int		status;
	char	*str;
	char	**argv;
	int		argc;
	pid_t	childPid;

	argc = 0;
	childPid = 0;
	if (!node)
		return 0;
	//child = node->first_child;
	argv = malloc(sizeof(char) * (256)); // 255 args and 1 for NULL  for less value remember it
	argc = PutValInStr(str, argc, argv, childFirst);
	if (argc == -3 || argc == -4)
		return (ErrDoCommand); 
	
}

