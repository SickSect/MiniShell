#include "minishell.h"
#include "parser.h"

#include "test.h"

char *ReadCmd(char *buf)
{
    int b_len;
    char *tmp;

    buf = get_next_line(0);
    b_len = ft_strlen(buf);
    buf[b_len - 1] = '\n';
    buf[b_len] = '\0';
    DisplayPrompt2();
    return (buf);

}

int	main(int argc, char **argv, char **env)
{
    char		*cmd;
    t_source	*source;

    while (1)
    {
        DisplayPrompt1();
        cmd = ReadCmd(cmd);
        if (!cmd)
            exit(EXIT_SUCCESS);
        if (cmd[0] == '\0' || strcmp(cmd, "\n") == 0)
        {
            free(cmd);
            continue;
        }
        if (ft_strcmp(cmd, "exit") == 0)
        {
            free(cmd);
            break ;
        }
        //printf(" YOU ENTERED %s\n", cmd);
        source = parse_str(cmd);
        //check_argv(source);
		//printf("LEN %ld CMD: %s\n", source.bufferSize, source.buffer);
        free(cmd);
    }
    exit (EXIT_SUCCESS);
}