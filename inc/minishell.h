#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

void	ft_putchar_fd(char c, int fd);
int		ft_isdigit(int ch);
char	*ft_strnew(size_t size);
char	*ft_strchr(const char *s, int c); //gnl
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
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
size_t	ft_strcpy(char *dest, const char *src);
char	*ft_strcat(char *str_a, char *str_b);
#endif