#include "minishell.h"

char	*ft_strcat(char *str_a, char *str_b)
{
    int		i;
	int		j;
	char 	*str;

	i = 0;
	j = 0;
	while (str_a[i] != '\0')
		i++;
	while(str_b[j] != '\0')
		j++;
	str = malloc(sizeof(char) * (i + j + 1));
	str[i + j] = '\0';
	i = 0;
	j = 0;
	while (str_a[i++] != '\0')
		str[i] = str_a[i];
	while (str_b[j] != '\0')
		str[i++] = str_b[j++];
	free(str_a);
	//str_a = str;
	return (str);
}