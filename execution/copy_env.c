/*
** copy_env.c for 42 in /home/dell-a_f/42sh/execution
** 
** Made by florian dell'aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Thu May 17 16:02:01 2012 florian dell'aiera
** Last update Thu May 17 17:38:27 2012 florian dell'aiera
*/

#include	"../parser/parser.h"
#include	"../42sh.h"
#include	"../lib/my.h"
#include	"execution.h"

void		init_compt(t_way *pt)
{
  pt->c_i = 0;
  pt->c_j = 0;
}

char		**copy_env(t_glob *glob, char **c_env, t_way *pt)
{
  int		k;
  int		size;
  t_env		*tmp;

  init_compt(pt);
  c_env = xmalloc(sizeof(char *) * (my_lenenv(glob) + 5));
  tmp = glob->env;
  while (tmp)
    {
      size = (my_strlen(tmp->name) + my_strlen(tmp->data) + 5);
      k = 0;
      c_env[pt->c_i] = xmalloc (sizeof(char) * size);
      while (tmp->name[k])
	c_env[pt->c_i][pt->c_j++] = tmp->name[k++];
      c_env[pt->c_i][pt->c_j++] = '=';
      k = 0;
      while (tmp->data[k])
	c_env[pt->c_i][pt->c_j++] = tmp->data[k++];
      c_env[pt->c_i++][pt->c_j] = '\0';
      pt->c_j = 0;
      tmp = tmp->next;
    }
  c_env[pt->c_i] = NULL;
  return (c_env);
}
