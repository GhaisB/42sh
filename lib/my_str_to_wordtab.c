/*
** my_str_to_wordtab.c for tab in /home/knocka_a/rendu/c/minishell1_re
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Mon Dec 19 14:30:20 2011 antoine knockaert
** Last update Thu May 17 10:11:58 2012 maxime sauvage
*/

#include	<stdlib.h>
#include	"my.h"

static int	count_oc(char *str, char c)
{
  int		i;
  int		count;

  count = 0;
  i = 0;
  while (str && str[i])
    {
      if (str[i] == c)
	{
	  count++;
	}
      i++;
    }
  return (count);
}

static char	**tabl_is_null()
{
  char		**tabl;

  tabl = xmalloc(1 * sizeof(char *));
  if (tabl)
    tabl[0] = NULL;
  return (tabl);
}

char		**my_str_to_wordtab(char *str, char c)
{
  int		i;
  int		j;
  int		k;
  char		**tabl;

  i = 0;
  j = 0;
  tabl = xmalloc((count_oc(str, c) + 5) * sizeof(char *));
  if (str == NULL || tabl == NULL)
    return (tabl_is_null());
  while (tabl && str && str[i] && str[i] == c)
    i++;
  while (tabl && str[i])
    {
      tabl[j] = xmalloc((my_strlen(str) + 2) * sizeof(char));
      k = 0;
      while (tabl[j] && str[i] && str[i] != c)
	tabl[j][k++] = str[i++];
      if (tabl[j])
	tabl[j++][k] = '\0';
      while (str && str[i] && str[i] == c)
	i++;
    }
  tabl[j] = NULL;
  return (tabl);
}
