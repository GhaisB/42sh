/*
** add_var_list.c for add_var_list in /home/knocka_a/repositories/42sh
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Fri Apr 13 15:17:42 2012 antoine knockaert
** Last update Thu May 17 10:15:59 2012 maxime sauvage
*/

#include	<stdio.h>
#include	<unistd.h>
#include	"../lib/my.h"
#include	"../42sh.h"
#include	"others.h"

int		add_var_end(t_glob *glob, char *name, char *value)
{
  t_var		*maillon;
  t_var		*tmp;

  tmp = glob->var;
  maillon = xmalloc(sizeof(t_var));
  if (maillon)
    {
      maillon->next = NULL;
      maillon->name = name;
      maillon->data = value;
      if (glob->var == NULL)
	glob->var = maillon;
      else
	{
	  while (tmp->next)
	    tmp = tmp->next;
	  tmp->next = maillon;
	}
      return (1);
    }
  else
    return (0);
}

void		add_var_list(t_glob *glob, char *str, int line)
{
  int		j;
  int		k;
  char		*name;
  char		*value;

  j = 0;
  k = 0;
  name = xmalloc((my_strlen(str) + 5) * sizeof(char));
  while (str && str[j] && str[j] != '=')
    name[k++] = str[j++];
  name[k] = 0;
  if (str[j] == 0)
    {
      xfree(name);
      printf("42sh: Warning: Config error on line %d (Ignored).\n", line);
      return;
    }
  k = 0;
  value = xmalloc((my_strlen(str) + 5) * sizeof(char));
  while (str && str[j])
    value[k++] = str[j++];
  value[k] = 0;
  add_var_end(glob, name, value);
}
