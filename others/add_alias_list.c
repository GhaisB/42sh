/*
** add_alias_list.c for add_alias in /home/knocka_a/repositories/42sh/others
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Sat May 12 11:05:55 2012 antoine knockaert
** Last update Thu May 17 10:14:08 2012 maxime sauvage
*/

#include	<stdlib.h>
#include	"../lib/my.h"
#include	"../42sh.h"
#include	"others.h"

int		add_alias_list(t_glob *glob, char *cmd, char *alias)
{
  t_alia	*maillon;
  t_alia	*tmp;

  tmp = glob->alias;
  maillon = xmalloc(sizeof(t_alia));
  if (maillon)
    {
      maillon->next = NULL;
      maillon->cmd = cmd;
      maillon->alias = alias;
      if (glob->alias == NULL)
	glob->alias = maillon;
      else
	{
	  while (tmp->next)
	    tmp = tmp->next;
	  tmp->next = maillon;
	}
      return (0);
    }
  else
    return (1);
}
