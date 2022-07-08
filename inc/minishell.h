
#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/wait.h>
# include <limits.h>
# include <errno.h>
# include <signal.h>

typedef struct s_need_to_be_global
{
	char	*token_buffer;
	int		token_b_size;
	int		token_b_index;
	t_src	*p_src;
	t_token	*p_roken;
}	t_global;

void	ft_putchar_fd(char c, int fd);
int		ft_isdigit(int ch);
char	*ft_strnew(size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_cut(char *str);
char	*ft_liner(char *str);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(const char *str);
int		ft_newline(const char *str);
int		ft_atoi(const char *str);
void    print_prompt1(void);
void    print_prompt2(void);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_astrjoin(char *s1, char *s2);

#endif