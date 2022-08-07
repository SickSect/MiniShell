#include "minishell.h"

static void	ft_cleaner(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
}

static int	ft_word(const char *str, char ch)
{
	size_t	i;
	size_t	word;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ch)
			i++;
		if (str[i])
			word++;
		while (str[i] != ch && str[i])
			i++;
	}
	return (word);
}

static char	*ft_subber(const char *s, size_t start, size_t end)
{
	size_t	i;
	size_t	j;
	char	*str;
	size_t	len;

	len = end - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}

static void	ft_proc(char const *s, char c, char **split)
{
	size_t	start;
	size_t	end;
	size_t	i;

	start = 0;
	end = 0;
	i = 0;
	while (i < (size_t)ft_word(s, c))
	{
		while (s[start] == c && s[start])
			start++;
		end = start;
		while (s[end] != c && s[end])
			end++;
		split[i] = ft_subber(s, start, end);
		if (split[i] == NULL)
		{
			ft_cleaner(split);
			return ;
		}
		start = end + 1;
		i++;
	}
	split[i] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (0);
	split = (char **)malloc(sizeof(char *) * (ft_word(s, c) + 1));
	if (!split)
	{
		free(split);
		return (0);
	}
	else if (split)
		ft_proc(s, c, split);
	return (split);
}