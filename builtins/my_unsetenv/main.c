/*
** main.c for main in /home/knocka_a/repositories/42sh/builtins/my_setenv
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Wed May  2 11:05:20 2012 antoine knockaert
** Last update Fri May 18 16:01:34 2012 antoine knockaert
*/

#include	<stdlib.h>
#include	"my_unsetenv.h"
#include	"../../42sh.h"
#include	"../../lib/my.h"
#include	"../../others/others.h"

void		unsetenv_all(t_glob *glob)
{
  t_env		*env;
  t_env		*tmp;

  env = glob->env;
  while (env)
    {
      tmp = env;
      xfree(env->name);
      xfree(env->data);
      env = env->next;
      xfree(tmp);
    }
  glob->env = NULL;
}

int		my_unsetenv(int ac, char **av, t_glob *glob)
{
  char		*name;
  t_env		*ptr;

  if (ac != 2)
    return (my_perror("setenv: Usage: unsetenv [name]\n", 2, -1, 1));
  name = NULL;
  if (av && av[1])
    name = av[1];
  if (my_match(name, "*"))
    unsetenv_all(glob);
  else if (name && ((ptr = my_getenv_ptr(av[1], glob->env)) != NULL))
    {
      xfree(ptr->name);
      xfree(ptr->data);
      if (ptr->prev)
	ptr->prev->next = ptr->next;
      if (ptr->next)
	ptr->next->prev = ptr->prev;
      xfree(ptr);
    }
  else
    return (my_perror("setenv: Can't delete. Not defined.\n", 2, -1, 1));
  return (1);
}
