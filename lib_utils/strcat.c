#include "inc/minishell.h"

void	ft_strcat(char *dest, char *src)
{
	size_t	i;

	i = 0;
	while (dest[i] != '\0')
		i++;
	while (*src)
	{
		dest[i] = *src;
		i++;
		src++;
	}
}