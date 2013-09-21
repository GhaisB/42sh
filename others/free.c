/*
** free.c for free in /home/knocka_a/repositories/42sh
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Fri May 18 16:23:55 2012 antoine knockaert
** Last update Sun May 20 15:04:19 2012 florian dell'aiera
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"../parser/parser.h"
#include	"../42sh.h"
#include	"others.h"

void		free_hist(t_glob *glob)
{
  t_hist	*tmp;
  t_hist	*tmp2;

  tmp = glob->hist;
  while (tmp)
    {
      tmp2 = tmp;
      xfree(tmp->cmd);
      tmp = tmp->next;
      xfree(tmp2);
    }
  glob->hist = NULL;
}

void		free_var(t_glob *glob)
{
  t_var		*tmp;
  t_var		*tmp2;

  tmp = glob->var;
  while (tmp)
    {
      tmp2 = tmp;
      xfree(tmp->name);
      xfree(tmp->data);
      tmp = tmp->next;
      xfree(tmp2);
    }
  glob->var = NULL;
}

void		free_alias(t_glob *glob)
{
  t_alia	*tmp;
  t_alia	*tmp2;

  tmp = glob->alias;
  while (tmp)
    {
      tmp2 = tmp;
      xfree(tmp->cmd);
      xfree(tmp->alias);
      tmp = tmp->next;
      xfree(tmp2);
    }
  glob->alias = NULL;
}

void		free_all(t_glob *glob)
{
  int		i;

  i = 0;
  unsetenv_all(glob);
  free_var(glob);
  free_alias(glob);
  free_hist(glob);
  while (glob->builtin[i])
    {
      xfree(glob->builtin[i]);
      i++;
    }
}
