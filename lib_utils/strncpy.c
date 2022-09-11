#include "inc/minishell.h"

char	*ft_strncpy(char *dest, const char *src, int n)
{
	size_t	i;

	i = 0;
	if (!src)
		return (NULL);
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}