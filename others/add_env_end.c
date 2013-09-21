/*
** add_env_end.c for 42sh in /home/knocka_a/repositories/42sh/others
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Tue Apr 10 16:59:04 2012 antoine knockaert
** Last update Sat May 12 15:17:21 2012 antoine knockaert
*/

#include	<stdlib.h>
#include	"../lib/my.h"
#include	"../42sh.h"
#include	"others.h"

int		add_env_end(t_glob *glob, char *name, char *value)
{
  t_env		*maillon;
  t_env		*tmp;

  tmp = glob->env;
  maillon = xmalloc(sizeof(t_env));
  if (maillon)
    {
      maillon->next = NULL;
      maillon->name = name;
      maillon->data = value;
      maillon->prev = NULL;
      if (glob->env == NULL)
	glob->env = maillon;
      else
	{
	  while (tmp->next)
	    tmp = tmp->next;
	  tmp->next = maillon;
	  maillon->prev = tmp;
	}
      return (1);
    }
  else
    return (0);
}
