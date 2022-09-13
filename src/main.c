#include "../inc/minishell.h"
#include "inc/lib_utils.h"

void actions(int signal_num, siginfo_t *info, void *old_info)
{
	int	i;

	i = -1;
	if (signal_num == SIGINT)
	{
		g_sig.ex_code = 130;
		ft_putstr_fd("\b\b\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		if (!g_sig.pid)
			rl_redisplay();
	}
	else if (signal_num == SIGQUIT)
	{
		ft_putchar_fd("\b\b", 1);
		rl_on_new_line();
		if (!g_sig.pid)
			rl_redisplay();
		else
		{
			ft_putendl_fd("Quit: 3", 1);
			g_sig.ex_code = 131;
		}
	}
}

t_mini	*zero_init(char **env)
{
	t_mini	*mini;

	mini = (t_mini *) malloc(sizeof(t_mini));
	if (!mini)
		return (NULL);
	mini->change.red_in = 1;
	mini->change.red_out = 2;
	mini->change.pipe = 3;
	mini->change.point_coma = 4;
	mini->change.tilda = 5;
	mini->change.gap = 6;
	mini->list = envp_copy(env);
	mini->cmds.in = dup(STDIN_FILENO);
	mini->cmds.out = dup(STDOUT_FILENO);
	mini->sig.sa_sigaction = actions;
	mini->sig.sa_flags = SA_SIGINFO;
	mini->history = NULL;
	mini->lst = NULL;
	return (mini);
}

char	**init_sh_lvl(char **env)
{
	int		i;
	char	*tmp;
	char	*sl;
	int		sh_lvl;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "SHLVL=", 6))
		i++;
	if (env[i])
	{
		sh_lvl = ft_atoi(env[i] + 6);
		tmp = ft_substr(env[i], 0, 6);
		sl = ft_itoa(++sh_lvl);
		env[i] = ft_strjoin(tmp, sl);
		free(sl);
	}
	return (env);
}

int	main(int argc, char **argv, char **env)
{
    t_mini	*mini;
	char	*str_s[10000]; // need opt

	g_sig.ex_code = 0; // ??
	env = init_sh_lvl(env);
	mini = zero_init(env);
}