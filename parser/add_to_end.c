/*
** add_to_end.c for 42sh in /home/bensaf_g//42sh/parser
** 
** Made by ghais bensafia
** Login   <bensaf_g@epitech.net>
** 
** Started on  Thu Apr 12 15:10:33 2012 ghais bensafia
** Last update Tue May 15 17:20:59 2012 ghais bensafia
*/

#include	"parser.h"

char		*check_semicolon(char *str)
{
  int		op;
  int		a;

  a = 0;
  op = 0;
  while (str[a])
    {
      if (str[a] != ';')
	op++;
      a++;
    }
  if (op != 0)
    return (str);
  str[0] = ';';
  str[1] = '\0';
  return (str);
}

t_pars          *add_to_end(char *com, char *token, t_pars *pars, t_pars *new)
{
  if ((new = xmalloc(sizeof(t_pars))) == NULL)
    return (NULL);
  if (token == NULL)
    new->token = NULL;
  else
    {
      token = check_semicolon(token);
      new->token = my_strdup(token);
    }
  if (com == NULL)
    new->command = NULL;
  else
    new->command = my_strdup(com);
  new->status = 0;
  new->arg = NULL;
  new->next = NULL;
  new->prev = pars;
  new->redir = NULL;
  new->redir_fich = NULL;
  new->left = NULL;
  new->right = NULL;
  new->success = 1;
  if (pars)
    pars->next = new;
  return (new);
}
