/*
** main.c for main in /home/knocka_a/repositories/42sh/builtins/my_setenv
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Wed May  2 11:05:20 2012 antoine knockaert
** Last update Tue May 15 11:22:41 2012 antoine knockaert
*/

#include	<stdlib.h>
#include	"../../others/others.h"
#include	"../../42sh.h"
#include	"../../lib/my.h"
#include	"my_setenv.h"

int		my_setenv(int ac, char **av, t_glob *glob)
{
  char		*data;
  char		*name;
  t_env		*ptr;

  if (ac != 2 && ac != 3)
    return (my_perror("setenv: Usage: setenv [name] [[data]]\n", 2, 0, 1));
  name = NULL;
  if (av && av[1])
    name = my_strdup(av[1]);
  if (ac == 3 && av && av[2])
    data = my_strdup(av[2]);
  else
    data = my_strdup("");
  if (name && (my_getenv(av[1], glob->env) == NULL))
    add_env_end(glob, name, data);
  else if (name && ((ptr = my_getenv_ptr(av[1], glob->env)) != NULL))
    ptr->data = data;
  else
    return (my_perror("setenv: An unknown error has occured.\n", 2, 0, 1));
  return (0);
}
