/*
** add_hist_end.c for add_hist_end in /home/knocka_a/repositories/42sh/others
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Mon Apr  9 20:08:58 2012 antoine knockaert
** Last update Wed May  2 16:29:53 2012 antoine knockaert
*/

#include	<stdlib.h>
#include	"../lib/my.h"
#include	"../42sh.h"
#include	"others.h"

int		add_hist_end(t_glob *glob, char *str)
{
  t_hist	*maillon;
  t_hist	*tmp;

  tmp = glob->hist;
  maillon = xmalloc(sizeof(t_hist));
  if (maillon)
    {
      maillon->next = NULL;
      maillon->cmd = my_strdup(str);
      if (glob->hist == NULL)
	{
	  maillon->prev = NULL;
	  glob->hist = maillon;
	}
      else
	{
	  while (tmp->next)
	    tmp = tmp->next;
	  tmp->next = maillon;
	  maillon->prev = tmp;
	}
      return (0);
    }
  else
    return (1);
}
