/*
** my_getenv_ptr.c for my_getenv2 in /home/knocka_a/repositories/42sh
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Wed May  2 11:16:30 2012 antoine knockaert
** Last update Wed May  2 11:17:01 2012 antoine knockaert
*/

#include	<stdlib.h>
#include	"../42sh.h"
#include	"my.h"

t_env		*my_getenv_ptr(char *name, t_env *envp)
{
  t_env		*tmp;

  tmp = envp;
  while (tmp)
    {
      if (my_match(name, tmp->name))
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}
