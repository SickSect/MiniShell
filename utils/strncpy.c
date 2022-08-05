#include "minishell.h"

char	*ft_strcpy(char *dest, const char *src, int n)
{
	size_t	i;

	i = 0;
	if (!src)
		return (-1);
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}