#ifndef LIB_UTILS_H
# define LIB_UTILS_H

#include "inc/minishell.h"

int		ft_atoi(const char *str);
int		ft_newline(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_astrjoin(char *s1, char *s2);
char	*ft_strnew(size_t size);
char	*get_next_line(int fd);
int	    ft_strcmp(const char *str1, const char *str2);
int	    ft_isalnum(int ch);
int	    ft_isdigit(int ch);
char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
char	**ft_split(char const *s, char c);
void	ft_strcat(char *dest, char *src);
char	*ft_strdup(const char *str_s);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
size_t	ft_strcpy(char *dest, const char *src);
int     ft_strlen(const char *str);
char	*ft_strncpy(char *dest, const char *src, int n);
int	    ft_strncmp(const char	*s1, const char *s2, size_t	n);
char	*ft_substr(char const	*s, unsigned int start, size_t	len);
void	ft_putendl_fd(char	*s, int fd);
#endif