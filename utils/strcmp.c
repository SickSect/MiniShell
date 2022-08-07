#include "minishell.h"

static int	ft_cmp(char a, char b)
{
	if ((unsigned char)a != (unsigned char)b)
	{
		return ((unsigned char)a - (unsigned char)b);
	}
	return (0);
}

int	ft_strcmp(const char *str1, const char *str2)
{
	size_t	i;

	i = 0;
	while (str1[i] && str2[i])
	{
		if (ft_cmp(str1[i], str2[i]) != 0)
		{
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		}
		i++;
	}
	return (0);
}