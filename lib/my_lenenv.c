/*
** my_lenenv.c for 42 sh in /home/dell-a_f/42sh/lib
** 
** Made by florian dell'aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Mon Apr 30 13:56:17 2012 florian dell'aiera
** Last update Wed May  2 17:13:45 2012 florian dell'aiera
*/

#include	"../42sh.h"

int		my_lenenv(t_glob *glob)
{
  int		i;
  t_env		*tmp;

  i = 0;
  tmp = glob->env;
  while (tmp)
    {
      tmp = tmp->next;
      i++;
    }
  return (i);
}
