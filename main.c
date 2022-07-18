#include "minishell.h"

char *reader(char *buf)
{
    int b_len;
    char *tmp;

    buf = get_next_line(0);
    b_len = ft_strlen(buf);
    buf[b_len - 1] = '\n';
    buf[b_len] = '\0';
    print_prompt2();
    return (buf);

}

int main(int argc, char **argv, char **env)
{
    char	*cmd;

	while (1)
	{
		print_prompt1();
		cmd = reader(cmd);
		if (!cmd)
			exit(EXIT_SUCCESS);
		if (cmd[0] == '\0' || strcmp(cmd, "\n") == 0)
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