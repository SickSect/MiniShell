#include "minishell.h"
#include <stdio.h>
#include <unistd.h>

/*
0 - STDIN
1 - STDOUT
2 - STDERR
*/
char *read_cmd(char *buf)
{
    int b_len;
    char *tmp;

    buf = get_next_line(0);
    b_len = ft_strlen(tmp);
    while (b_len > 1 && buf[b_len - 1] == '\\')
    {
        buf[b_len - 1] = '\n';
        buf[b_len] = '\0';
        print_prompt2();
        tmp = buf;
        buf = get_next_line(0);
        buf = ft_strjoin(tmp, buf);
        b_len = ft_strlen(buf);
    }
    return (buf);

}

int	main(int argc, char **argv, char **env)
{
    int flg = 0;
    char *cmd;

    while (flg == 0)
    {
        print_prompt1();
        cmd = read_cmd(cmd);
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
            break ;
        }
        write(1, cmd, ft_strlen(cmd));
        write(1, "\n", 1);
        free(cmd);
    }
    exit (EXIT_SUCCESS);
}