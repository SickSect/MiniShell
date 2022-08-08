#include "minishell.h"
#include "parser.h"
#include "test.h"

static void trim_newline(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i] == '\n')
		str[i] = '\0';
}

static char *parse_per_token(char *str)
{
	char	*spaced_str;
	char	**tokens;
	int		i;
	int		j;

	i = 0;
	j = 0;
	spaced_str = malloc(sizeof(char) * (get_len_with_spaces(str)));
	while (str[i])
	{
		if (str[i] == '|')
		{
			spaced_str[j++] = ' ';
			if (str[i + 1] != ' ' && str[i])
			{
				spaced_str[j++] = '|';
				spaced_str[j++] = ' ';
				i++;
			}
		}
		spaced_str[j++] = str[i++];
	}
	return (spaced_str);
}

t_source *parse_str(char *str)
{
    char		**spl_str;
    t_source	*src;
	
	src = malloc(sizeof(t_source));
	if (!src)
		return (NULL);
	src->command = str;
	src->str_len = ft_strlen(str);
	src->spaced_str = parse_per_token(str);
	trim_newline(src->spaced_str);
	return (src);
}