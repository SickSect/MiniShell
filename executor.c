#include "minishell.h"
#include "executor.h"

static void	SearchStep(char *path, char *p, char *p2)
{
	ft_strncpy(path, p, p2 - p);
	path[p2 - p] = '\0';
	if (pw[-1] != '/')
		ft_strcat();
}

char	*SearchPath(char *file, char *getEnvPath)
{
	char	*p;
	char	*p2;
	int		pLen;
	char	*path;

	while (*p && p)
	{
		p2 = p;
		while (*p2 && *p2 != ':')
			p2++;
		pLen = p2 - p;
		if (!pLen)
			pLen = 1;
		path = malloc(sizeof(char) * (pLen + 1 + ft_strlen(file) + 1));
		SearchStep(path, p, p2);
	}
}