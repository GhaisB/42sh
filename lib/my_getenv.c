/*
** my_getenv.c for my_getenv in /home/knocka_a/repositories/42sh/lib
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Mon Apr 30 14:42:01 2012 antoine knockaert
** Last update Wed May  2 17:22:52 2012 florian dell'aiera
*/

#include	<stdlib.h>
#include	"../42sh.h"
#include	"my.h"

char		*my_getenv(char *name, t_env *envp)
{
  t_env		*tmp;

  tmp = envp;
  while (tmp)
    {
      if (my_match(name, tmp->name))
	return (tmp->data);
      tmp = tmp->next;
    }
  return (NULL);
}
