/*
** init.c for init in /home/maitre_c//Mes_Programmes/42sh/parser
** 
** Made by antoine maitre
** Login   <maitre_c@epitech.net>
** 
** Started on  Fri May 18 16:15:30 2012 antoine maitre
** Last update Fri May 18 16:39:51 2012 antoine maitre
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "parser.h"

char	*fonction(char *str, char *s)
{
  int	i;

  i = 0;
  if (!s)
    return (NULL);
  str = xmalloc(sizeof(char) * (my_strlen(s) + 1));
  if (!str)
    return (NULL);
  while (s[i])
    {
      str[i] = s[i];
      i++;
    }
  str[i] = '\0';
  return (str);
}

int	find_parenth(char *s)
{
  int	i;
  int	j;

  i = 0;
  j = 2;
  if (!s)
    return (0);
  while (s[i])
    {
      if (s[i] == '"')
	j++;
      if (s[i] == '(' && j % 2 == 0)
	return (1);
      i++;
    }
  return (0);
}

char	*epur_p_bis(char *str, char *s, int tmp1, int tmp2)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (str[i])
    {
      if (i != tmp1 && i != tmp2)
	s[j++] = str[i++];
      else
	i++;
    }
  s[j] = '\0';
  free(str);
  return (s);
}

char	*epur_p(char *str)
{
  int	i;
  int	tmp1;
  int	tmp2;
  char	*s;

  i = 0;
  tmp1 = 0;
  tmp2 = 0;
  if (!str)
    return (NULL);
  while (str[i] != '(')
    i++;
  tmp1 = i;
  while (str[i])
    i++;
  while (str[i] != ')')
    i--;
  tmp2 = i;
  s = xmalloc(sizeof(char) * (my_strlen(str) + 1));
  if (s)
    s = epur_p_bis(str, s, tmp1, tmp2);
  return (s);
}
