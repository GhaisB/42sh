/*
** handle.c for 42sh in /home/bensaf_g//42sh/parser
** 
** Made by ghais bensafia
** Login   <bensaf_g@epitech.net>
** 
** Started on  Thu Apr 12 14:21:15 2012 ghais bensafia
** Last update Fri May 18 16:10:26 2012 antoine maitre
*/

#include	"parser.h"

int		handle_op(char *str, int i, int *a, t_pars **pars)
{
  char		*stock;
  int		b;

  b = *a;
  if ((stock  = xmalloc((my_strlen(str) + 5) * sizeof(char))) == NULL)
    return (0);
  init_str(stock, (my_strlen(str) + 4));
  while (str && str[b] && ((str[b] != ' ') && (is_alpha_numeric(str[b]) == 0)))
    {
      stock[i] = str[b];
      b++;
      i++;
    }
  stock[i] = '\0';
  if ((*pars = add_to_end(NULL, stock, *pars, NULL)) == NULL)
    return (0);
  free(stock);
  *a = b;
  return (1);
}

int		handle_parent(char *str, int i, int *a, t_pars **pars)
{
  int		open_parent;
  int		close_parent;
  int		b;
  char		*stock;

  if ((stock = xmalloc((my_strlen(str) + 5) * sizeof(char))) == NULL)
    return (0);
  declaration(&close_parent, &open_parent, &b, *a);
  count_open(&open_parent, str, &b);
  while (str && str[b] && (close_parent < open_parent))
    {
      if (str[b] == ')')
	close_parent++;
      b++;
    }
  open_parent = b;
  b = *a;
  while (str && str[b] && (b <= open_parent))
    stock[i++] = str[b++];
  stock[i] = '\0';
  *a = b;
  if ((*pars = add_to_end(stock, NULL, *pars, NULL)) == NULL)
    return (0);
  free(stock);
  return (1);
}

int		handle_quote(char *str, int i, int *a, t_pars **pars)
{
  char		*stock;
  int		b;

  b = *a;
  if ((stock  = xmalloc((my_strlen(str) + 5) * sizeof(char))) == NULL)
    return (0);
  init_str(stock, (my_strlen(str) + 4));
  stock[i++] = str[b++];
  while (str && str[b] && str[b] != '"')
    {
      stock[i] = str[b];
      b++;
      i++;
    }
  stock[i++] = str[b];
  stock[i] = '\0';
  b++;
  *a = b;
  if ((*pars = add_to_end(stock, NULL, *pars, NULL)) == NULL)
    return (0);
  free(stock);
  return (1);
}

int		handle_command(char *str, int i, int *a, t_pars **pars)
{
  char		*stock;
  int		b;

  b = *a;
  if ((stock = xmalloc((my_strlen(str) + 5) * sizeof(char))) == NULL)
    return (0);
  init_str(stock, (my_strlen(str) + 4));
  while (str && str[b] && (is_an_op(str[b]) == 0))
    {
      stock[i] = str[b];
      b++;
      i++;
    }
  stock[i] = '\0';
  *a = b;
  if ((*pars = add_to_end(stock, NULL, *pars, NULL)) == NULL)
    return (0);
  free(stock);
  return (1);
}
