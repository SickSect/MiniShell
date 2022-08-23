#include "minishell.h"
#include "parser.h"

char	*get_path_till_colon(char *file, char *a_path, char *b_path)
{
	int 	path_a_len;
	int		path_b_len;
	char	*path_till_colon;

	path_b_len = b_path - a_path;
	if (!path_b_len)
		path_b_len = 1;
	path_a_len = ft_strlen(file);
	path_till_colon = malloc(sizeof(char) * (path_a_len + path_b_len + 2));
	if (!path_till_colon)
	{
		errno = ENOMEM;
		return (NULL);
	}
	path_till_colon = ft_strncpy(path_till_colon, a_path, b_path - a_path);
	path_till_colon[b_path - a_path] = '\0';
	printf("RETURNED PATH IS %s\n", path_till_colon);
	return (path_till_colon);
}


char	*search_cycle(char *file, char *a_path, char *b_path, char *env_paths)
{
	struct stat		st;
	char			*try_path;

	while(a_path && *a_path)
	{
		b_path = a_path;
		while (*b_path && *b_path != ':')
			b_path++;
		try_path = get_path_till_colon(file, a_path, b_path);
		if (try_path[-1] != '/')
			ft_strcat(try_path, "/");
		ft_strcat(try_path, file);
		if (stat(try_path, &st) == 0)
		{
			if (!S_ISREG(st.st_mode))
			{
				errno = ENOENT;
				a_path = b_path;
				if (*b_path == ':')
					a_path++;
				continue;
			}
			a_path = malloc(sizeof(char) * (ft_strlen(try_path) + 1));
			if (!a_path)
				return (NULL);
			ft_strcpy(a_path, try_path);
			return (a_path);
		}
		else
		{
			a_path = b_path;
			if (*b_path == ':')
				a_path++;
		}
	}
	errno = ENOENT;
	return (NULL);
}

char    *search_path(char *file)
{
    char	*a_path;
    char	*b_path;
	char	*env_paths;
	char	*path_to_command;

	env_paths = getenv("PATH");
	a_path = env_paths;
	path_to_command = search_cycle(file, a_path, b_path, env_paths);
	return (path_to_command);
}

/*
char	*search_path(char *file)
{
	char *PATH = getenv("PATH");
	char *p    = PATH;
	char *p2;
	
	while(p && *p)
	{
		p2 = p;
		while(*p2 && *p2 != ':')
		{
			p2++;
		}
		
		int  plen = p2-p;
		if(!plen)
		{
			plen = 1;
		}
		
		int  alen = strlen(file);
		char path[plen+1+alen+1];
		
		strncpy(path, p, p2-p);
		path[p2-p] = '\0';
		
		if(p2[-1] != '/')
		{
			strcat(path, "/");
		}
		strcat(path, file);
		
		struct stat st;
		if(stat(path, &st) == 0)
		{
			if(!S_ISREG(st.st_mode))
			{
				errno = ENOENT;
				p = p2;
				if(*p2 == ':')
				{
					p++;
				}
				continue;
			}
			p = malloc(strlen(path)+1);
			if(!p)
			{
				return NULL;
			}
			strcpy(p, path);
			return p;
		}
		else    
		{
			p = p2;
			if(*p2 == ':')
			{
			p++;
			}
		}
	}
	errno = ENOENT;
	return NULL;
}

*/