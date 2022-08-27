/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 20:07:41 by wbeck             #+#    #+#             */
/*   Updated: 2022/08/27 16:35:33 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "minishell.h"
#include "symtab/symtab.h"

// Здесь происходит инициализация стека таблиц символов и глобальной таблицы символов. 
// В следующей части идет чтение списка переменных окружения и добавление их в таблицу символов.

void	initsh_utils(int len, t_symtab_entry *entry, char **p2, char *eq)
{
	char name[len + 1];

	strncpy(name, *p2, len);
	name[len] = '\0';
	// entry = add_to_symtab(name);
	if (entry)
	{
		// symtab_entry_setval(entry, eq + 1);
		entry->flags |= FLAG_EXPORT;
	}
}

// Эта функция инициализирует стек таблиц символов (включая глобальную таблицу символов) и сканирует список окружений, 
// добавляя в таблицу каждую переменную окружения (и ее значение). 
// Наконец, функция добавляет две переменные, которые мы будем использовать для хранения строк приглашения, PS1 и PS2.

void	init_sh(char **env)
{
	t_symtab_entry	*entry; // что это??
	char			**temp_env;
	char			*eq; // переназвать нужно, а то непонятно
	int				len;

	temp_env = env;
	init_symtab();
	while (*temp_env)
	{
		eq = strchr(*temp_env, '=');
		if (eq)
		{
			len = ft_strlen(eq) - ft_strlen(*temp_env);
			// init_sh_utils(len, entry, temp_env, eq);
		}
		else
			// entry = add_to_symtab(*temp_env);
		temp_env++;
	}
	// entry = add_to_symtab("PS1");
	// symtab_entry_setval(entry, "$ ");
	// entry = add_to_symtab("PS2");
	// symtab_entry_setval(entry, "> ");
}