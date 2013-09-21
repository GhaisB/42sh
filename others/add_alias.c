/*
** add_alias.c for add_alias in /home/knocka_a/repositories/42sh
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Sat May 12 10:46:54 2012 antoine knockaert
** Last update Sun May 13 18:48:59 2012 antoine knockaert
*/

#include	"others.h"
#include	"../42sh.h"

void		add_alias(t_glob *glob, char *str)
{
  int		i;
  int		j;
  char		*cmd;
  char		*alias;

  cmd = xmalloc((my_strlen(str) + 5) * sizeof(char));
  alias = xmalloc((my_strlen(str) + 5) * sizeof(char));
  i = 0;
  while (str && str[i] && str[i] != ' ')
    i++;
  i++;
  if (str && str[i] && str[i] == '\'')
    i++;
  j = 0;
  while (str && str[i] && str[i] != '\'' && str[i] != '=')
    cmd[j++] = str[i++];
  cmd[j] = 0;
  while (str && str[i] && (str[i] == '=' || str[i] == '\''))
    i++;
  j = 0;
  while (str && str[i] && str[i] != '\'')
    alias[j++] = str[i++];
  alias[j] = 0;
  add_alias_list(glob, cmd, alias);
}
