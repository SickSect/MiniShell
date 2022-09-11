#include "inc/minishell.h"

int	ft_isalnum(int ch)
{
	return ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z')
		|| (ch >= 'A' && ch <= 'Z'));
}