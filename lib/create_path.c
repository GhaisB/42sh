/*
** exec_bin.c for minishell in /home/knocka_a/rendu/c/minishell1_re
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Tue Dec 20 14:53:05 2011 antoine knockaert
** Last update Sun May 20 22:22:54 2012 antoine knockaert
*/

#include	"my.h"

char		*create_path(char *path, char *filename)
{
  char		*path_final;
  int		taille;
  int		i;
  int		j;

  i = 0;
  j = 0;
  taille = my_strlen(path) + my_strlen(filename) + 3;
  path_final = xmalloc(taille * sizeof(char));
  if (path_final != NULL)
    {
      while (path && path[i])
	path_final[j++] = path[i++];
      if (path_final[j-1] != '/')
	path_final[j++] = '/';
      i = 0;
      while (filename && filename[i])
	path_final[j++] = filename[i++];
      path_final[j] = 0;
      return (path_final);
    }
  return (NULL);
}
