/*
** link.c for 42 in /home/dell-a_f/42sh
** 
** Made by florian dell'aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Sun May 20 15:13:20 2012 florian dell'aiera
** Last update Sun May 20 15:13:21 2012 florian dell'aiera
*/

#include "parser.h"

void		make_token(t_pars **pars, t_pars **tmp, char ***tab)
{
  (*pars) = (*tmp);
  (*pars)->prev->next = NULL;
  if ((*pars)->next)
    {
      (*pars)->next->prev = NULL;
      (*pars)->right = make_link(tab, (*pars)->next);
      (*pars)->right->prev = (*pars);
    }
  (*pars)->left = make_link(tab, (*pars)->prev);
  (*pars)->left->prev = (*pars);
}

void		make_command(t_pars **pars)
{
  char		**tabl;

  tabl = my_str_to_wordtab((*pars)->command, ' ');
  if (!tabl)
    (*pars) = NULL;
  if (!tabl[0])
    (*pars) = NULL;
  if (find_parenth((*pars)->command) != 1 && find_r((*pars)->command) != 1)
    (*pars)->command = my_strdup(tabl[0]);
  if (find_parenth((*pars)->command) != 1 && find_r((*pars)->command) != 1)
    (*pars)->arg = tabl;
  (*pars)->left = NULL;
  (*pars)->right = NULL;
}

void		make_link_bis(t_pars **pars, t_pars **tmp, char ***tab)
{
  if ((*tmp))
    make_token(&(*pars), &(*tmp), tab);
  else
    make_command(&(*pars));
}

t_pars		*make_link(char ***tab, t_pars *pars)
{
  int		i;
  t_pars	*tmp;

  i = 0;
  tmp = NULL;
  while (pars->prev)
    pars = pars->prev;
  while (tab[i] && !tmp)
    tmp = find_link(tab[i++], pars);
  make_link_bis(&pars, &tmp, tab);
  return (pars);
}
