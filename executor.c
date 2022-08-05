#include "minishell.h"
#include "executor.h"

static char	*ReturnPathOrNull(char *p, char *path)
{
	p = malloc(sizeof(char) * (ft_strlen(path) + 1));
	if (!p)
		return (NULL);
	ft_strcpy(p, path);
}

static int GetPathLen(char *p, char *p2)
{
	int pLen;

	p2 = p;
	while (*p2 && *p2 != ':')
		p2++;
	pLen = p2 - p;
	if (!pLen)
			pLen = 1;
	return (pLen);
}

static char	*PathCopierCaller(char *p, char *p2, int pLen, char *file)
{
	char *path;

	path = malloc(sizeof(char) * (pLen + 1 + ft_strlen(file) + 1));
	ft_strncpy(path, p, p2 - p);
	path[p2 - p] = '\0';
	if (p2[-1] != '/')
		ft_strcat(path, "/");
	ft_strcat(path, file);
	return path;
}

static char	*SearchStepCycle(char *Path, char *p, char *p2, char *file)
{
	int			pLen;
	char		*path;
	struct stat	st;

	while (p && *p)
	{
		pLen = GetPathLen(p, p2);
		path = PathCopierCaller(p, p2, pLen, file);
		if (stat(path, &st) == 0)
		{
			if (!S_ISREG(st.st_mode))
			{
				errno = ENOENT;
				p = p2;
				if (*p2 == ':')
					p++;
				continue;
			}
			return ReturnPathOrNull(p, path);
		}
		else
			FileNotFoundInPath(p, p2);
	}
	errno = ENOENT;
	return (NULL);
}

char	*SearchPath(char *file)
{
	char	*p;
	char	*p2;
	char	*Path;

	Path = getenv("PATH");
	p = Path;
	return SearchStepCycle(Path, p, p2, file);
}