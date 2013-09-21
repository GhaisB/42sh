/*
** init_parser.c for 42sh in /home/bensaf_g//42sh/parser
** 
** Made by ghais bensafia
** Login   <bensaf_g@epitech.net>
** 
** Started on  Mon May 14 18:36:57 2012 ghais bensafia
** Last update Fri May 18 16:08:25 2012 antoine maitre
*/

#include	<stdio.h>
#include	"parser.h"

int		check_semi_colon(char *str)
{
  int		a;
  int		b;

  b = 0;
  a = 0;
  while (str[a])
    {
      if (str[a] != ';')
	b++;
      a++;
    }
  if (b == 0)
    return (0);
  return (1);
}

int		init_parser(char *str, t_pars **pars)
{
  int		a;

  (*pars) = NULL;
  a = 0;
  if ((!str) || (my_strlen(str) == 0))
    return (0);
  if (check_semi_colon(str) == 0)
    return (0);
  if ((parser(str, a, pars)) == 0)
    return (0);
  while ((*pars)->prev)
    (*pars) = (*pars)->prev;
  return (1);
}
