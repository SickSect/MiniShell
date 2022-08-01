#include "parser_node.h"
#include "scanner.h"
#include "minishell.h"
#include "source.h"

static t_node *CycleSimpleCmd(t_token *token, t_node *cmd, t_source *source)
{
	t_node		*word;
	
	while(token != NULL)
	{
		if (token->text[0] == '\n')
		{
			FreeToken(token);
			break;
		}
		word = NewNode(NODE_VAR);
		if (!word)
		{
			FreeNodeTree(cmd);
			FreeToken(token);
			return (NULL);
		}
		SetNodeValStr(word, token->text);
		AddChildNode(cmd, word);
		FreeToken(token);
	}
	return (cmd);
}

struct node_s *ParseSimpleCmd(t_token *token)
{
    t_node		*cmd;
    t_source	*source;

    if (!token)
        return (NULL);
    cmd = NewNode(NODE_COMMAND);
    if (!cmd)
    {
        FreeToken(token);
        return (NULL);
    }
	source = token->source;
	cmd = CycleSimpleCmd(token, cmd, source);
	return (cmd);
}