#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

size_t 	ft_strcpy(char *dest, const char *src);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
int		ft_strlen(const char *str);
#endif