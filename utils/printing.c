#include "minishell.h"

void    print_in_fd(int fd, char *str)
{
    write(fd, &str, ft_strlen(str));
}

void    print_str_with_char(char *str, char ch, int fd)
{
    print_in_fd(stderr, str);
    write(fd, "'", 1);
    write(fd, &ch, 1);
    write(fd, "'", 1);
    write(fd, "\n", 1);
}