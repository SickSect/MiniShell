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
		if (cmd[0] = '\0' || )
	}
}