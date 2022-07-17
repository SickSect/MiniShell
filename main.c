#include "minishell.h"
int main(int argc, char **argv, char **env)
{
    char	*cmd;

	while (1)
	{
		//print_prompt();
		cmd = reader(cmd);
		if (!cmd)
			exit(EXIT_SUCCESS);
		if (cmd[0] = '\0' || strcmp(cmd, "\n") == 0)
		{
			free(cmd);
			continue;
		}
		if (strcmp(cmd, "exit") == 0)
		{
			free(cmd);
			break;
		}
		write(1, cmd, ft_strlen(cmd));
		write(1, "\n", 1);
		if (cmd)
			free(cmd);
	}
	exit(EXIT_SUCCESS);
}