#include "minishell.h"
#include "parser.h"

#include "test.h"

/*
ls -a |wc -l
ls -a|wc -l
ls -a | wc -l
*/
char *read_cmd(char *buf)
{
    int b_len;
    char *tmp;

    buf = get_next_line(0);
    b_len = ft_strlen(buf);
    while (b_len > 1 && buf[b_len - 1] == '\\')
    {
        buf[b_len - 1] = '\n';
        buf[b_len] = '\0';
        display_prompt2();
        tmp = buf;
        buf = get_next_line(0);
        buf = ft_strjoin(tmp, buf);
        b_len = ft_strlen(buf);
    }
    return (buf);

}

int	main(int argc, char **argv, char **env)
{
    char		*cmd;
    t_source	*source;

    while (1)
    {
        display_prompt1();
        cmd = read_cmd(cmd);
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
        source = parse_str(cmd);
        free(cmd);
    }
    exit (EXIT_SUCCESS);
}