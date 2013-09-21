/*
** parser.c for 42sh in /home/bensaf_g//42sh/parser
** 
** Made by ghais bensafia
** Login   <bensaf_g@epitech.net>
** 
** Started on  Thu Apr 12 13:45:25 2012 ghais bensafia
** Last update Mon May 14 13:25:51 2012 ghais bensafia
*/

#include	"parser.h"

int		is_an_op(char c)
{
  int		a;

  a = 0;
  while (LABEL_OPERAND[a])
    {
      if (c == LABEL_OPERAND[a])
	return (1);
      a++;
    }
  a = 0;
  if (c == '(')
    return (2);
  if (c == '"')
    return (3);
  return (0);
}

int		parser(char *str, int a, t_pars **pars)
{
  int		i;
  int		ret;

  ret = 1;
  i = 0;
  while (str && str[a] == ';')
    a++;
  while (str && str[a])
    {
      if (str && str[a] && is_an_op(str[a]) == 1)
	ret = handle_op(str, i, &a, pars);
      else if (str && str[a] && is_an_op(str[a]) == 2)
	ret = handle_parent(str, i, &a, pars);
      else if (str && str[a] && is_an_op(str[a]) == 3)
	ret = handle_quote(str, i, &a, pars);
      else if (str && str[a] && (is_an_op(str[a]) == 0) && (str[a] != ' '))
	ret = handle_command(str, i, &a, pars);
      else if (str && str[a] && (str[a] == ' '))
	a++;
      if (ret != 1)
	return (0);
    }
  if ((ret = handle_last(pars)) != 1)
    return (0);
  return (1);
}
