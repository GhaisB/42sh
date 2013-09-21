/*
** find_pars.c for find in /home/maitre_c//Mes_Programmes/42sh/parser
** 
** Made by antoine maitre
** Login   <maitre_c@epitech.net>
** 
** Started on  Fri May 18 16:14:31 2012 antoine maitre
** Last update Fri May 18 16:14:34 2012 antoine maitre
*/

#include "parser.h"

int	find_nb_par(char *str)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  k = 0;
  while (str[i])
    {
      if (str[i] == '(')
	j++;
      if (str[i] == ')')
	k++;
      i++;
    }
  if (k == j)
    return (1);
  else
    return (0);
}

int	find_r(char *str)
{
  int	i;

  i = 0;
  if (!str)
    return (0);
  while (str[i])
    {
      if (str[i] == '>' || str[i] == '<')
	return (1);
      i++;
    }
  return (0);
}

int	find_dif(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] && s2[i])
    {
      if (s1[i] != s2[i])
	return (0);
      i++;
    }
  if (s1[i] == s2[i])
    return (1);
  else
    return (0);
}

t_pars	*find_link(char **tab, t_pars *pars)
{
  int	i;

  while (pars->prev)
    pars = pars->prev;
  while (pars)
    {
      i = 0;
      if (!pars->command)
	{
	  while (tab[i])
	    {
	      if (find_dif(tab[i], pars->token))
		return (pars);
	      i++;
	    }
	}
      pars = pars->next;
    }
  return (NULL);
}

