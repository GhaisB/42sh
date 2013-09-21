/*
** redir.c for sùfl in /home/bensaf_g//42sh/parser
** 
** Made by ghais bensafia
** Login   <bensaf_g@epitech.net>
** 
** Started on  Fri May 18 16:41:25 2012 ghais bensafia
** Last update Sun May 20 15:43:17 2012 antoine maitre
*/

#include "parser.h"

void	error_redir(t_pars **pars)
{
  if ((*pars)->left)
    error_redir(&(*pars)->left);
  if ((*pars)->right)
    error_redir(&(*pars)->right);
  if ((*pars)->redir)
    {
      if (my_strlen((*pars)->redir) > 2)
	(*pars)->success = 0;
      if ((*pars)->redir_fich)
	if (find_r((*pars)->redir_fich))
	  (*pars)->success = 0;
      if ((*pars)->redir[0] == '>' && (*pars)->redir[1] == '<')
	(*pars)->success = 0;
      if ((*pars)->redir[0] == '<' && (*pars)->redir[1] == '>')
	(*pars)->success = 0;
    }
}

char	*my_epur_red(char *str)
{
  char	*s;
  int	i;
  int	j;

  j = 0;
  i = 0;
  s = xmalloc(sizeof(char) * (my_strlen(str) + 2));
  if (s == NULL)
    return (NULL);
  while (str[i])
    if (str[i] != '>' || str[i] != '<')
      s[j++] = str[i++];
    else
      {
	s[j++] = ' ';
	while ((str[i] == '>' || str[i] == '<') && str[i])
	  s[j++] = str[i++];
	s[j++] = ' ';
      }
  s[j] = '\0';
  return (s);
}

char		*epur_redir_fich(char *src)
{
  int		a;
  int		b;
  char		*dest;

  dest = xmalloc(sizeof(char) * (my_strlen(src) + 5));
  b = 0;
  a = 0;
  while (src && src[a] && src[a] == ' ')
    a++;
  while (src && src[a] && src[a] != ' ')
    dest[b++] = src[a++];
  dest[b] = '\0';
  xfree(src);
  return (dest);
}

void	 complet_redir(t_pars **pars, char **tab)
{
  if (tab)
    if (tab[0])
      if (tab[1])
	if (tab[2])
	  {
	    (*pars)->arg = my_str_to_wordtab(tab[0], ' ');
	    (*pars)->command = tab[0];
	    (*pars)->redir = tab[1];
	    (*pars)->redir_fich = epur_redir_fich(tab[2]);
	  }
	else
	  (*pars)->success = 0;
      else
	(*pars)->success = 0;
    else
      (*pars)->success = 0;
  else
    (*pars)->success = 0;
}
