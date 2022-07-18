#include "minishell.h"

char *reader(char *cmd)
{
	int b_len;
    char *tmp;

    cmd = get_next_line(0);
    b_len = ft_strlen(cmd);
    while (b_len > 1 && cmd[b_len - 1] == '\\')
    {
        cmd[b_len - 1] = '\n';
        cmd[b_len] = '\0';
        print_prompt2();
        tmp = cmd;
        cmd = get_next_line(0);
        cmd = ft_strjoin(tmp, cmd);
        b_len = ft_strlen(cmd);
    }
    return (cmd);
}

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