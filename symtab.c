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

// add_to_symtab() добавляет новую запись в локальную таблицу символов. 
// Каждая запись (переменная или функция) должна иметь уникальный ключ, т.е. имя (мы задаем это имя сами).
// Чтобы обеспечить эту уникальность, мы сначала проверяем,
// существует ли запись с заданным именем, вызывая do_lookup().
// Если запись с заданным именем существует, мы просто возвращаем существующую запись, не добавляя новую.
// В противном случае мы добавим запись, установим ее имя и настроим указатели таблицы символов.
// Возвращаем только что добавленную запись.

t_symtab_entry	*do_lookup(char *str, t_symtab *symtab)
{
	t_symtab_entry	*entry;

	if (!str || !symtab)
		return (NULL);
	entry = symtab->first;
	while (entry)
	{
		if (!strcmp(entry->name, str))
			return (entry);
		entry = entry->next;
	}
	return (NULL);
}

void	add_to_symtab_utils(t_symtab_entry *entry, t_symtab *symtab, char *symbol)
{
	entry->name = malloc(ft_strlen(symbol) + 1);
	if (!entry->name)
	{
		printf("fatal error: no memory for new symbol table entry\n");
		// exit(EXIT_FAILURE);
	}
	strcpy(entry->name, symbol);
	if (!symtab->first)
	{
		symtab->first = entry;
		symtab->last = entry;
	}
	else
	{
		symtab->last->next = entry;
		symtab->last = entry;
	}
}

t_symtab_entry		*add_to_symtab(char *symbol)
{
	t_symtab_entry	*entry;
	t_symtab_stack	*symtab_stack;
	t_symtab		*symtab;

	if (!symbol || symbol[0] == '\0')
		return (NULL);
	symtab = symtab_stack.local_symtab;
	entry = NULL;
	if ((entry = do_lookup(symbol, symtab)))
		return (entry);
	entry = malloc(sizeof(t_symtab_entry));
	if (!entry)
	{
		printf("fatal error: no memory for new symbol table entry\n");
		// exit(EXIT_FAILURE);
	}
	memset(entry, 0, sizeof(t_symtab_entry)); // нужно добавить memset или это встроенная ?
	add_to_symtab_utils(entry, symtab, symbol);
	return (entry);
}

// rem_from_symtab() удаляет запись таблицы символов, ключ которой соответствует заданному имени
int	rem_from_symtab_utils(t_symtab_entry *entry, t_symtab *symtab)
{
	t_symtab_entry *node_1;
	t_symtab_entry *node_2;

	node_2 = NULL;
	node_1 = symtab->first;
	while (node_1 && node_1 != entry)
	{
		node_2 = node_1;
		node_1 = node_1->next;
	}
	if (node_1 == entry)
	{
		node_2->next = entry->next;
		return (1);
	}
}

int	rem_from_symtab(t_symtab_entry *entry, t_symtab *symtab)
{
	int res;

	res = 0;
	if (entry->val)
		free(entry->val);
	if (entry->func_body)
		free_node_tree(entry->func_body);
	free(entry->name);
	if (symtab->first == entry)
	{
		symtab->first = symtab->first->next;
		if (symtab->last == entry)
			symtab->last = NULL;
		res = 1;
	}
	else
		res = rem_from_symtab_utils(entry, symtab);
	free(entry);
	return (res);
}

// get_symtab_entry() ищет запись таблицы символов, ключ которой соответствует заданному имени. 
// На первый взгляд это может показаться излишним, поскольку мы уже определили функцию do_lookup()
// для поиска в локальной таблице символов.
// Разница здесь в том, что get_symtab_entry() ищет весь стек, начиная с локальной таблицы символов. 

t_symtab_entry		*get_symtab_entry(char *str)
{
	int				i;
	t_symtab		*symtab;
	t_symtab_entry	*entry;

	i = symtab_stack.symtab_count - 1;
	symtab = symtab_stack.symtab_list[i];
	entry = do_lookup(str, symtab);
	if (entry)
		return (entry);
	while (--i >= 0)
	{
		symtab = symtab_stack.symtab_list[i];
		entry = do_lookup(str, symtab);
		if (entry)
			return (entry);
	}
	return (NULL);
}

// symtab_entry_setval() освобождает память, используемую для хранения значения старой записи (если таковое существует). 
// Затем он создает копию нового значения и сохраняет его в записи таблицы символов.

void	symtab_entry_setval(t_symtab_entry *entry, char *val)
{
	char	*val2;

	if (entry->val)
		free(entry->val);
	if (!val)
		entry->val = NULL;
	else
	{
		val2 = malloc(ft_strlen(val) + 1);
		if (val2)
			strcpy(val2, val);
		else
			printf("error: no memory for symbol table entry's value\n");
		entry->val = val2;
	}
}

// Функции Стека Таблиц Символов
// Эти функции помогут нам работать со стеком таблиц символов.


// symtab_stack_add() добавляет данную таблицу символов в стек и назначает вновь добавленную таблицу в качестве локальной таблицы символов.
void	symtab_stack_add(t_symtab *symtab)
{
	symtab_stack.symtab_list[symtab_stack.symtab_count++] = symtab;
	symtab_stack.local_symtab = symtab;
}

// symtab_stack_push() создает новую пустую таблицу символов и помещает ее поверх стека.
t_symtab	*symtab_stack_push(void)
{
	t_symtab		*st;

	st = new_symtab(++symtab_level); // этот левел есть в инициализации
	symtab_stack_add(st);
	return (st);
}

// symtab_stack_pop() удаляет (или всплывает) таблицу символов поверх стека, регулируя указатели стека по мере необходимости.
t_symtab	*symtab_stack_pop(void)
{
	t_symtab	*st;

	if (symtab_stack.symtab_count == 0)
		return (NULL);
	st = symtab_stack.symtab_list[symtab_stack.symtab_count - 1];
	symtab_stack.symtab_list[--symtab_stack.symtab_count] = NULL;
	g_symtab_level--;
	if (symtab_stack.symtab_count == 0)
	{
		symtab_stack.local_symtab = NULL;
		symtab_stack.global_symtab = NULL;
	}
	else
		symtab_stack.local_symtab = symtab_stack.symtab_list[symtab_stack.symtab_count - 1];
	return (st);
}

// get_local_symtab() возвращаeт указатели на локальную таблицу символов.
t_symtab	*get_local_symtab(void)
{
	return (symtab_stack.local_symtab);
}

// get_global_symtab() возвращаeт указатели на глобальную таблицу символов.
t_symtab	*get_global_symtab(void)
{
	return (symtab_stack.global_symtab);
}

// get_symtab_stack() возвращает указатель на стек таблицы символов.
t_symtab_stack	*get_symtab_stack(void)
{
	return (&symtab_stack);
}
