#include "minishell.h"
#include "src.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n > 0)
	{
		while (i < (n - 1) && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = 0;
	}
	while (src[i])
		i++;
	return (i);
}

size_t	ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	if (!src)
		return (ERR_CPY);
	while (str[i])
	{
		dest[i] = src[i];
		i++;
	}
	src[i] = '\0';
	return (i);
}