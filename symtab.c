/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symtab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 20:20:37 by wbeck             #+#    #+#             */
/*   Updated: 2022/08/27 16:36:06 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "shell.h"
#include "node.h"
#include "parser.h"
#include "symtab.h"
// Функция init_symtab() инициализирует наш стек таблиц символов,
// затем выделяет память для глобальной таблицы символов и инициализирует ее.

void	init_symtab(void)
{
	t_symtab_stack	symtab_stack; // указатель на стек таблиц символов
	t_symtab		global_symtab;
	int				symtab_level;

	symtab_stack.symtab_count = 1;
	symtab_level = 0; // текущий уровень в стеке
	global_symtab = malloc(sizeof(t_symtab));
	if (!global_symtab)
	{
		printf("fatal error: no memory for new symbol table\n");
		exit(EXIT_FAILURE);
	}
	memset(global_symtab, 0, sizeof(t_symtab));
	symtab_stack.global_symtab = global_symtab;
	symtab_stack.local_symtab = global_symtab;
	symtab_stack.symtab_list[0] = global_symtab;
	global_symtab->level = 0;
}

// Функция отладки, которая выводит содержимое локальной таблицы символов.
// Для визуализации
void	dump_local_symtab(t_symtab *symtab)
{
	t_symtab_entry	*entry;
	int				i;
	int				indent;

	i = 0;
	indent = symtab->level * 4;
	printf("%*sSymbol table [Level %d]:\r\n", indent, " ", symtab->level);
	printf("%*s===========================\r\n", indent, " ");
	printf("%*s  No               Symbol                    Val\r\n", indent, " ");
	printf("%*s------ -------------------------------- ------------\r\n", indent, " ");
	entry = symtab->first;
	while (entry)
	{
		printf("%*s[%04d] %-32s '%s'\r\n", indent, " ",	i++, entry->name, entry->val);
		entry = entry->next;
	}
	printf("%*s------ -------------------------------- ------------\r\n", indent, " ");
}

// Функция new_symtab() нужна для создания новой таблицы символов 
// (например, когда мы собираемся выполнить функцию оболочки)
t_symtab	*new_symtab(int level)
{
	t_symtab		*symtab;

	symtab = malloc(sizeof(t_symtab));
	if (!symtab)
	{
		printf("fatal error: no memory for new symbol table\n");
		exit(EXIT_FAILURE);
	}
	memset(symtab, 0, sizeof(t_symtab));
	symtab->level = level;
	dump_local_symtab(symtab)
	return (symtab);
}

// Мы вызовем функцию free_symtab (), когда закончим работу с таблицей символов, 
// и мы хотим освободить память, используемую таблицей символов и ее записями.
void	free_symtab(t_symtab *symtab)
{
	t_symtab_entry	*entry;
	t_symtab_entry	*next;

	if (!symtab)
		return ;
	entry = symtab->first;
	while (entry)
	{
		if (entry->name)
			free(entry->name);
		if (entry->val)
			free(entry->val);
		if (entry->func_body)
			free_node_tree(entry->func_body);
		next = entry->next;
		free(entry);
		entry = next;
	}
	free(symtab);
}




// void				add_to_symtab_util(t_symtab_entry *entry, \
// 						t_symtab *st, char *symbol)
// {
// 	entry->name = malloc(ft_strlen(symbol) + 1);
// 	if (!entry->name)
// 	{
// 		fprintf(stderr, "fatal error: no memory for new symbol table entry\n");
// 		exit(EXIT_FAILURE);
// 	}
// 	strcpy(entry->name, symbol);
// 	if (!st->first)
// 	{
// 		st->first = entry;
// 		st->last = entry;
// 	}
// 	else
// 	{
// 		st->last->next = entry;
// 		st->last = entry;
// 	}
// }

// t_symtab_entry		*add_to_symtab(char *symbol)
// {
// 	t_symtab_entry	*entry;
// 	t_symtab		*st;

// 	if (!symbol || symbol[0] == '\0')
// 		return (NULL);
// 	st = g_symtab_stack.local_symtab;
// 	entry = NULL;
// 	if ((entry = do_lookup(symbol, st)))
// 		return (entry);
// 	entry = malloc(sizeof(t_symtab_entry));
// 	if (!entry)
// 	{
// 		fprintf(stderr, "fatal error: no memory for new symbol table entry\n");
// 		exit(EXIT_FAILURE);
// 	}
// 	memset(entry, 0, sizeof(t_symtab_entry));
// 	add_to_symtab_util(entry, st, symbol);
// 	return (entry);
// }

// t_symtab_entry		*do_lookup(char *str, t_symtab *symtable)
// {
// 	t_symtab_entry	*entry;

// 	if (!str || !symtable)
// 		return (NULL);
// 	entry = symtable->first;
// 	while (entry)
// 	{
// 		if (strcmp(entry->name, str) == 0)
// 			return (entry);
// 		entry = entry->next;
// 	}
// 	return (NULL);
// }

// t_symtab_entry		*get_symtab_entry(char *str)
// {
// 	int				i;
// 	t_symtab		*symtab;
// 	t_symtab_entry	*entry;

// 	i = g_symtab_stack.symtab_count - 1;
// 	symtab = g_symtab_stack.symtab_list[i];
// 	entry = do_lookup(str, symtab);
// 	if (entry)
// 		return (entry);
// 	while (--i >= 0)
// 	{
// 		symtab = g_symtab_stack.symtab_list[i];
// 		entry = do_lookup(str, symtab);
// 		if (entry)
// 			return (entry);
// 	}
// 	return (NULL);
// }

// void				symtab_entry_setval(t_symtab_entry *entry, char *val)
// {
// 	char			*val2;

// 	if (entry->val)
// 		free(entry->val);
// 	if (!val)
// 		entry->val = NULL;
// 	else
// 	{
// 		val2 = malloc(ft_strlen(val) + 1);
// 		if (val2)
// 			strcpy(val2, val);
// 		else
// 			fprintf(stderr, "error: no memory for symbol table entry's value\n");
// 		entry->val = val2;
// 	}
// }

// int					rem_from_symtab_utils(t_symtab_entry *entry, \
// 						t_symtab *symtab)
// {
// 	t_symtab_entry *e;
// 	t_symtab_entry *p;

// 	p = NULL;
// 	e = symtab->first;
// 	while (e && e != entry)
// 	{
// 		p = e;
// 		e = e->next;
// 	}
// 	if (e == entry)
// 	{
// 		p->next = entry->next;
// 		return (1);
// 	}
// }

// int					rem_from_symtab(t_symtab_entry *entry, t_symtab *symtab)
// {
// 	int res;

// 	res = 0;
// 	if (entry->val)
// 		free(entry->val);
// 	if (entry->func_body)
// 		free_node_tree(entry->func_body);
// 	free(entry->name);
// 	if (symtab->first == entry)
// 	{
// 		symtab->first = symtab->first->next;
// 		if (symtab->last == entry)
// 			symtab->last = NULL;
// 		res = 1;
// 	}
// 	else
// 		res = rem_from_symtab(entry, symtab);
// 	free(entry);
// 	return (res);
// }

// void				symtab_stack_add(t_symtab *symtab)
// {
// 	g_symtab_stack.symtab_list[g_symtab_stack.symtab_count++] = symtab;
// 	g_symtab_stack.local_symtab = symtab;
// }

// t_symtab			*symtab_stack_push(void)
// {
// 	t_symtab		*st;

// 	st = new_symtab(++g_symtab_level);
// 	symtab_stack_add(st);
// 	return (st);
// }

// t_symtab			*symtab_stack_pop(void)
// {
// 	t_symtab		*st;

// 	if (g_symtab_stack.symtab_count == 0)
// 		return (NULL);
// 	st = g_symtab_stack.symtab_list[g_symtab_stack.symtab_count - 1];
// 	g_symtab_stack.symtab_list[--g_symtab_stack.symtab_count] = NULL;
// 	g_symtab_level--;
// 	if (g_symtab_stack.symtab_count == 0)
// 	{
// 		g_symtab_stack.local_symtab = NULL;
// 		g_symtab_stack.global_symtab = NULL;
// 	}
// 	else
// 		g_symtab_stack.local_symtab = \
// 			g_symtab_stack.symtab_list[g_symtab_stack.symtab_count - 1];
// 	return (st);
// }

// t_symtab			*get_local_symtab(void)
// {
// 	return (g_symtab_stack.local_symtab);
// }

// t_symtab			*get_global_symtab(void)
// {
// 	return (g_symtab_stack.global_symtab);
// }

// t_symtab_stack		*get_symtab_stack(void)
// {
// 	return (&g_symtab_stack);
// }
