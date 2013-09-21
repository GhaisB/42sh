/*
** tree.c for norme in /home/dell-a_f/42sh
** 
** Made by florian dell'aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Sun May 20 15:13:31 2012 florian dell'aiera
** Last update Sun May 20 16:49:42 2012 florian dell'aiera
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "parser.h"
#include "../42sh.h"

char	***make_operand_tab(void)
{
  char	***tabl;

  tabl = malloc(sizeof(char **) * 4);
  if (tabl == NULL)
    return (NULL);
  tabl[0] = malloc(sizeof(char *) * 2);
  tabl[1] = malloc(sizeof(char *) * 3);
  tabl[2] = malloc(sizeof(char *) * 7);
  if (!tabl[0] || !tabl[1] || !tabl[2])
    return (NULL);
  tabl[0][0] = fonction(tabl[0][0], SEMICOLON);
  tabl[0][1] = NULL;
  tabl[1][0] = fonction(tabl[1][0], OR);
  tabl[1][1] = fonction(tabl[1][1], AND);
  tabl[1][2] = NULL;
  tabl[2][0] = fonction(tabl[2][0], PIPE);
  tabl[2][1] = fonction(tabl[2][1], LEFT_RED);
  tabl[2][2] = fonction(tabl[2][2], D_LEFT_RED);
  tabl[2][3] = fonction(tabl[2][3], RIGHT_RED);
  tabl[2][4] = fonction(tabl[2][4], D_RIGHT_RED);
  tabl[2][5] = NULL;
  tabl[3] = NULL;
  return (tabl);
}

void		finish_tree(t_pars **pars, t_glob *glob)
{
  t_pars	*tmp;

  if ((*pars)->command != NULL)
    {
      if (find_parenth((*pars)->command))
	{
	  if (find_nb_par((*pars)->command))
	    {
	      tmp = (*pars)->prev;
	      (*pars) = make_tree(epur_p((*pars)->command), glob);
	      if ((*pars))
		(*pars)->prev = tmp;
	    }
	  else
	    (*pars)->success = 0;
	}
    }
  if ((*pars) && (*pars)->left)
    finish_tree(&(*pars)->left, glob);
  if ((*pars) && (*pars)->right)
    finish_tree(&(*pars)->right, glob);
}

void		free_tab(char ***tabl)
{
  int		i;
  int		j;

  j = 0;
  if (tabl)
    {
      while (tabl[j])
	{
	  i = 0;
	  while (tabl[j][i])
	    {
	      xfree(tabl[j][i]);
	      i++;
	    }
	  xfree(tabl[j++]);
	}
      xfree(tabl);
    }
}

t_pars		*make_tree_bis(t_pars *pars, char ***tab, t_glob *glob)
{
  t_pars	*tmp;

  tmp = NULL;
  pars = make_link(tab, pars);
  finish_tree(&pars, glob);
  tmp = pars;
  redir(&pars);
  error_redir(&pars);
  error_null(&pars);
  check_the_tree(pars, &tmp);
  if (pars->success == 1)
    pars->prev = NULL;
  else
    free_the_tree(&pars);
  return (pars);
}

t_pars 		*make_tree(char *str, t_glob *glob)
{
  char		***tab;
  t_pars	*pars;

  tab = NULL;
  tab = make_operand_tab();
  init_parser(str, &pars);
  epur_pars(&pars);
  gere_alias_pars(&pars, glob);
  error_tok_end(&pars, pars);
  if (pars && pars->token)
    pars->success = 0;
  if (tab && pars)
    {
      error_pars(&pars, tab);
      if (pars->success == 1)
	pars = make_tree_bis(pars, tab, glob);
      else
	free_the_tree(&pars);
    }
  if (tab)
    free_tab(tab);
  return (pars);
}
