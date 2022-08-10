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

void	do_simple_cmd(t_source	*source, char **enpv)
{
	pid_t	child_pid;
	int		status;

	child_pid = 0;
	if (!source)
		return ;
	if (!(child_pid = fork()))
	{
		if(!(source->cmd_path))
			return ;
		execve(source->cmd_path, source->splitted_str, enpv);
	}
	waitpid(child_pid, NULL, 0);
	return ;
}

int	main(int argc, char **argv, char **enpv)
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
        // это редактируем полученную строку
        source = parse_str(cmd);
        free(cmd);
        // сплитую для удобства проверки, проверяю как работает поиск путя к команде
        source->splitted_str = ft_split(source->spaced_str, ' ');
        // printf("full str is |%s|\n|%s| send to func\n", source->spaced_str, source->splitted_str[0]);
        // собственно вызываю функцию и тут будет лежать путь к команде
        source->cmd_path = search_path(source->splitted_str[0]);
        if (!(source->cmd_path))
        {
            printf("not found");
            return 0;
        }
        else
        {
            // printf("path to command %s is : %s\n", source->splitted_str[0], source->cmd_path);
            do_simple_cmd(source, enpv);
            return 0;
        }
        //  преобразовать уже преобразованные данные еще и в двусвязный список с типа и перечеслдениями 
        //  вызвать функцию по выполнению команды
        // 
    }
    return 0;
}