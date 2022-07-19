#include "minishell.h"
#include "scaner.h"
#include "syntax.h"
#include "parser.h"

struct node_s *parse_simple_command(t_token *tk)
{
    t_node      *cmd;
    t_source    *src;
    t_node      *word;

    if (!tk)
        return (NULL);
    cmd = new_node(NODE_COMMAND);
    if (!cmd)
    {
        free(tk);
        return (NULL);
    }
    src = tk->src;
    while((tk = tokenize(src)) != &eof_token)
    {
        if (tk->text[0] == '\n')
        {
            free(tk);
            break;
        }
        word = new_node(NODE_VAR);
        if (!word)
        {
            free_node_tree(cmd);
            free_token(tk);
            return (NULL);
        }
        set_node_val_str(word, tk->text);
        add_child_node(cmd, word);
        free_token(tk);
    }
    return (cmd);
}