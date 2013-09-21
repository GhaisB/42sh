/*
** error_pars.c for 42 in /home/dell-a_f/42sh
** 
** Made by florian dell'aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Sun May 20 15:13:09 2012 florian dell'aiera
** Last update Sun May 20 15:13:09 2012 florian dell'aiera
*/

#include "parser.h"

void		check_the_tree(t_pars *pars, t_pars **tmp)
{
  if (pars->success == 0)
    (*tmp)->success = 0;
  if (pars->left)
    check_the_tree(pars->left, &(*tmp));
  if (pars->right)
    check_the_tree(pars->right, &(*tmp));
}

int		error_tok(char *str, char ***tabl)
{
  int		i;
  int		j;

  i = 0;
  while (tabl[i])
    {
      j = 0;
      while (tabl[i][j])
	{
	  if (find_dif(tabl[i][j], str) == 1)
	    return (0);
	  j++;
	}
      i++;
    }
  return (1);
}

void		error_tok_end(t_pars **tmp, t_pars *pars)
{
  if (pars)
    {
      while (pars->next)
	pars = pars->next;
      if (pars && pars->token)
	if (pars->token[0] != ';')
	  (*tmp)->success = 0;
    }
}

void		error_null(t_pars **pars)
{
  if ((*pars)->token)
    {
      if ((*pars)->left)
	error_null(&(*pars)->left);
      else if ((*pars)->token[0] != ';')
	(*pars)->success = 0;
      if ((*pars)->right)
	error_null(&(*pars)->right);
      else if ((*pars)->token[0] != ';')
	(*pars)->success = 0;
    }
}

void		error_pars(t_pars **pars, char ***tabl)
{
  t_pars	*tmp;

  while ((*pars)->prev)
    (*pars) = (*pars)->prev;
  tmp = (*pars);
  while ((*pars))
    {
      if ((*pars)->command && (*pars)->next)
	if ((*pars)->next->command)
	  tmp->success = 0;
      if ((*pars)->token && (*pars)->next)
	if ((*pars)->next->token)
	    tmp->success = 0;
      (*pars) = (*pars)->next;
    }
  (*pars) = tmp;
  while ((*pars))
    {
      if ((*pars)->token)
	if (error_tok((*pars)->token, tabl))
	  tmp->success = 0;
      (*pars) = (*pars)->next;
    }
  (*pars) = tmp;
}
