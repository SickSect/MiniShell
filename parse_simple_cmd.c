/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_simple_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:00:26 by wbeck             #+#    #+#             */
/*   Updated: 2022/08/27 16:41:40 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// РАЗБОР ПРОСТЫХ КОМАНД

// Здесь будет происходит анализ сиктаксиса
// Синтаксический анализатор - это часть интерпретатора командой строки, которая вызывает лесический сканер(Леша реализовывал) для извлечения маркеров.
// Маркер - это все, кроме символов-разделителей (пробелы, табуляция, символ новой строки). Для игнорировая символов-разделитей используются кавычки (н-р, строка)
#include "minishell.h"
#include "node.h"
#include "token.h"

static char	*init_utils(t_token *token, t_node *cmd)
{
	cmd = new_node(NODE_COMMAND);
	if(!cmd || tok->text[0] == '\n')
	{
		// free_token(token); //функции нет
		return (NULL);
	}
	word = new_node(NODE_VAR);
	if (!word)
	{
		free_node_tree(cmd);
		// free_token(token); //функции нет
		return (cmd);
	}
	set_node_val_str(word, tok->text);
	add_child_node(cmd, word);
	// free_token(token); //функции нет
}

struct node_s	*parse_simple_cmd(s_token *token)
{
	t_node		*cmd;
	t_node		*word;
	t_source	*src;
 
	if (!token)
		return (NULL);
	if (init_utils(token, cmd))
		return (init_utils(token, cmd));
	else
		return (init_utils(token, cmd));
	src = token->src;
	while (!token) //здесь должна быть какая-то переменная, которая говорит об окончании команды
	{	
		if (init_utils(token, cmd))
			return (init_utils(token, cmd));
		else
			return (init_utils(token, cmd));
	token = tokenize(src);
	}
	return (cmd);
}
