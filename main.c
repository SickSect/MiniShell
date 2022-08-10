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
        printf("OK\n");
        source->splitted_str = ft_split(source->spaced_str, ' ');
        printf("full str is |%s|\n|%s| send to func\n", source->spaced_str, source->splitted_str[0]);
        source->command_path = search_path(source->splitted_str[0]);
        printf("OK\n");
        printf("path to command %s is : %s\n", source->splitted_str[0], source->command_path);
        free(cmd);
    }
    exit (EXIT_SUCCESS);
}