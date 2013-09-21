/*
** init.c for 42sh in /home/knocka_a/repositories/42sh/others
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Mon Apr  9 13:25:03 2012 antoine knockaert
** Last update Mon May 14 14:04:49 2012 antoine knockaert
*/

#include	<stdlib.h>
#include	"../lib/my.h"
#include	"../42sh.h"
#include	"others.h"

void		init_glob(t_glob *glob)
{
  glob->env = NULL;
  glob->hist = NULL;
  glob->var = NULL;
  glob->alias = NULL;
  glob->exit = 0;
  glob->exit_code = EXIT_SUCCESS;
}

t_glob		*init(int ac, char **av, char **envp)
{
  t_glob	*glob;

  ac = ac;
  av = av;
  glob = xmalloc(sizeof(t_glob));
  if (glob)
    {
      init_glob(glob);
      if (!init_env(glob, envp))
	return (NULL);
      if (!init_history(glob))
	return (NULL);
      if (!init_builtins(glob))
	return (NULL);
      glob->var = NULL;
      init_config(glob);
    }
  return (glob);
}
