/*
** copy_wordtab.c for copy in /home/knocka_a/lem-in/lib
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Wed Mar 28 14:13:43 2012 antoine knockaert
** Last update Thu Apr 26 17:24:34 2012 antoine knockaert
*/

#include	<stdlib.h>
#include	"my.h"

char		**copy_wordtab(char **str)
{
  char		**ret;
  int		i;
  int		size;
  char		*tmp;

  i = 0;
  size = my_tablen(str);
  ret = xmalloc((size + 1) * sizeof(char *));
  while (ret && str[i])
    {
      tmp = my_strdup(str[i]);
      if (tmp)
	ret[i] = tmp;
      else
	ret[i] = NULL;
      i++;
    }
  return (ret);
}
