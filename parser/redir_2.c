/*
** redir_2.c for mùdksfsd in /home/bensaf_g//42sh/parser
** 
** Made by ghais bensafia
** Login   <bensaf_g@epitech.net>
** 
** Started on  Fri May 18 16:41:56 2012 ghais bensafia
** Last update Fri May 18 16:42:33 2012 ghais bensafia
*/

#include "parser.h"

int	is_dir(char c)
{
  if (c == '>')
    return (1);
  if (c == '<')
    return (1);
  return (0);
}

char	*init_and_malloc(int len)
{
  char	*str;

  str = xmalloc(sizeof(char) * (len + 5));
  init_str(str, (len + 5));
  return (str);
}

char	**fill_d_tab(char *str)
{
  char	**dab;
  int	a;
  int	b;

  b = 0;
  a = 0;
  dab = xmalloc(4 * sizeof(char *));
  while (b < 4)
    dab[b++] = init_and_malloc(my_strlen(str));
  b = 0;
  while (str && str[a] && is_dir(str[a]) == 0)
    dab[0][b++] = str[a++];
  b = 0;
  while (str && str[a] && str[a] == ' ')
    a++;
  while (str && str[a] && is_dir(str[a]) == 1)
    dab[1][b++] = str[a++];
  b = 0;
  while (str && str[a])
    dab[2][b++] = str[a++];
  dab[3] = NULL;
  return (dab);
}

void	redir(t_pars **pars)
{
  char	**tab;

  if ((*pars)->command == NULL)
    {
      if ((*pars)->left)
	redir(&(*pars)->left);
      if ((*pars)->right)
	redir(&(*pars)->right);
    }
  if (find_r((*pars)->command))
    {
      tab = fill_d_tab((*pars)->command);
      complet_redir(&(*pars), tab);
    }
}
