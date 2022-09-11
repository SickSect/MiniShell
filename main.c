
#include "inc/structures.h"
#include "inc/minishell.h"

char	**init_sh_lvl(char **env)
{

}

int	main(int argc, char **argv, char **env)
{
    t_mini	*mini;
	char	*str_s[10000]; // need opt

	g_sig.ex_code = 0; // ??
	env = init_sh_lvl(env);
}