/*
** gere_alias_pars.c for alias_pars in /home/maitre_c//Mes_Programmes/42sh/parser
** 
** Made by antoine maitre
** Login   <maitre_c@epitech.net>
** 
** Started on  Fri May 18 16:14:46 2012 antoine maitre
** Last update Fri May 18 16:14:48 2012 antoine maitre
*/

#include "parser.h"
#include "../42sh.h"
#include "../prompt/prompt.h"

void		gere_alias_pars(t_pars **pars, t_glob *list)
{
  t_pars	*tmp;

  tmp = (*pars);
  if ((*pars))
    {
      while ((*pars)->prev)
	(*pars) = (*pars)->prev;
      while ((*pars)->next)
	{
	  if ((*pars)->command)
	    {
	      (*pars)->command = replace_alias(list, (*pars)->command);
	    }
	  (*pars) = (*pars)->next;
	}
    }
  (*pars) = tmp;
}
