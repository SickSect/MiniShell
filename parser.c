#include "minishell.h"
#include "parser.h"
#include "test.h"

static char *parse_per_token(char *str)
{
	printf("\n|START PARSE STRING|\n");
	char	*spaced_str;
	//char	**tokens;
	int		i;
	int		j;

	i = 0;
	j = 0;
	spaced_str = malloc(sizeof(char) * (get_len_with_spaces(str)));
	//printf("|last len %d new_len %d|\n", ft_strlen(str), get_len_with_spaces(str));
	while (str[i])
	{
		if (str[i] == '|')
		{
			spaced_str[j] = ' ';
			j++;
			if (str[i + 1] != ' ' && str[i])
			{
				
			}
		}
		spaced_str[j] = str[i];
		i++;
		j++;
	}
	printf("|SPACED STR IS %s|\n", spaced_str);
	return (spaced_str);
}

t_source *parse_str(char *str)
{
	printf("\n|START PARSING|\n");
    char		**spl_str;
    t_source	*src;
	
	src = malloc(sizeof(t_source));
	if (!src)
		return (NULL);
	src->buf_str = str;
	src->cmd = parse_per_token(str);
	return (src);
}