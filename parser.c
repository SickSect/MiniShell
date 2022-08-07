#include "minishell.h"
#include "parser.h"
#include "test.h"

void rewrite_spl_str(char **before, char **after, int pipe_pos)
{
	/*
	int	i;
	int	j;
	int	k;
	char **new_pipe;

	i = 0;
	j = 0;
	k = 0;
	while (before[i])
	{
		if (i == pipe_pos)
		{
			new_pipe = ft_split(before[i], '|');
			after[j] = new_pipe[0];
			j++;
			after[j] = "|";
			j++;
			if (new_pipe[1] != NULL)
			{
				after[j] = new_pipe[1];
				j++;
			}
			i++;		
		}
		after[j] = before[i];
		j++;
		i++;
	}
	*/
	
}

char **last_split(char **spl_str, int amount)
{
	size_t	i;
	char **newspl_str;

	i = 0;
	while (spl_str[i])
	{
		if (ft_strchr(spl_str[i], '|'))
		{
			//newspl_str = malloc(sizeof(char *) * (amount + 3));
			newspl_str = ft_split(spl_str[i], '|');
			print_str(newspl_str);
			sleep(2);
			//rewrite_spl_str(spl_str, newspl_str, i);
		}
		i++;
	}
	return (newspl_str);
}


t_source *parse_str(char *str)
{
    char		**spl_str;
    t_source	*src;
	int			amount_spl;

    spl_str = ft_split(str, ' ');
	amount_spl = 0;
	while (spl_str[amount_spl])
		amount_spl++;
	src = malloc(sizeof(t_source));
	if (!src)
		return (NULL);
	src->buf_str = str;
	src->str_len = ft_strlen(str);
	src->substr_arg = spl_str;
	src->substr_arg = last_split(spl_str, amount_spl);
	return (src);
}