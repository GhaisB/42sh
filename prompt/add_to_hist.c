/*
** add_var_list.c for add_var_list in /home/knocka_a/repositories/42sh
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Fri Apr 13 15:17:42 2012 antoine knockaert
** Last update Sat May  5 14:33:08 2012 antoine knockaert
*/

#include	<stdio.h>
#include	<unistd.h>
#include	"../lib/my.h"
#include	"../42sh.h"
#include	"prompt.h"

int		add_hist_beg(t_glob *glob, char *cmd)
{
  t_hist	*maillon;

  maillon = xmalloc(sizeof(t_var));
  if (maillon)
    {
      maillon->next = glob->hist;
      if (glob->hist)
	glob->hist->prev = maillon;
      maillon->prev = NULL;
      maillon->cmd = cmd;
      glob->hist = maillon;
      return (1);
    }
  else
    return (0);
}
