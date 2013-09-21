/*
** init_env.c for 42sh in /home/knocka_a/repositories/42sh/others
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Tue Apr 10 16:42:42 2012 antoine knockaert
** Last update Thu May 17 17:39:04 2012 antoine knockaert
*/

#include	<stdlib.h>
#include	"../lib/my.h"
#include	"../42sh.h"
#include	"others.h"

static int	init_one_env(char *env, t_glob *glob)
{
  int		j;
  int		k;
  char		*name;
  char		*value;

  j = 0;
  k = 0;
  if ((name = xmalloc((my_strlen(env) + 5) * sizeof(char))) == NULL)
    return (0);
  while (env && env[j] && env[j] != '=')
    name[k++] = env[j++];
  name[k] = 0;
  k = 0;
  j++;
  if ((value = xmalloc((my_strlen(env) + 5) * sizeof(char))) == NULL)
    return (0);
  while (env && env[j])
    value[k++] = env[j++];
  value[k] = 0;
  if (!add_env_end(glob, name, value))
    return (0);
  return (1);
}

int		init_env(t_glob *glob, char **envp)
{
  int		i;
  int		ret;

  i = 0;
  while (envp && envp[i])
    {
      ret = init_one_env(envp[i], glob);
      if (!ret)
	return (0);
      i++;
    }
  return (1);
}
