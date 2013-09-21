/*
** handle_2.c for 42sh in /home/bensaf_g//42sh/parser
** 
** Made by ghais bensafia
** Login   <bensaf_g@epitech.net>
** 
** Started on  Mon May 14 18:25:51 2012 ghais bensafia
** Last update Wed May 16 14:11:44 2012 antoine maitre
*/

#include	"parser.h"

int		is_alpha_numeric(char c)
{
  if (c >= 'a' && c <= 'z')
    return (1);
  if (c >= 'A' && c <= 'Z')
    return (1);
  if (c >= '0' && c <= '9')
    return (1);
  return (0);
}

void		declaration(int *close_parent, int *open_parent, int *b, int a)
{
  int		tmp;

  tmp = 0;
  *close_parent = tmp;
  *open_parent = tmp;
  *b = a;
}

void		count_open(int *open_parent, char *str, int *b)
{
  int		a;
  int		tmp;

  tmp = *open_parent;
  a = *b;
  while (str && str[a] && str[a] != ')')
    {
      if (str[a] == '(')
	tmp++;
      a++;
    }
  *b = a;
  *open_parent = tmp;
}

int		handle_last(t_pars **pars)
{
  char		*str;

  str = xmalloc(sizeof(char) * 2);
  str[0] = ';';
  str[1] = '\0';
  if ((*pars = add_to_end(NULL, str, *pars, NULL)) == NULL)
    return (0);
  free(str);
  return (1);
}
