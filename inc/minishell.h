
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

void	ft_putchar_fd(char c, int fd);
int		ft_isdigit(int ch);
char	*ft_strnew(size_t size);
int		ft_strcmp(const char *str1, const char *str2);
char	*ft_strchr(const char *s, int c);
char	*ft_cut(char *str);
char	*ft_liner(char *str);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(const char *str);
int		ft_newline(const char *str);
int		ft_atoi(const char *str);
void    DisplayPrompt1(void);
void    DisplayPrompt2(void);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_astrjoin(char *s1, char *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
char    ft_realloc(char *str, int size);
size_t	ft_strcpy(char *dest, const char *src);

#endif