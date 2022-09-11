#include "inc/minishell.h"

char	*ft_strdup(const char *str_s)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(str_s) + 1));
	if (!str)
		return (NULL);
	while (str_s[i])
	{
		str[i] = str_s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}