/*
** epur_pars.c for epur_pars in /home/maitre_c//Mes_Programmes/42sh/parser
** 
** Made by antoine maitre
** Login   <maitre_c@epitech.net>
** 
** Started on  Fri May 18 16:14:21 2012 antoine maitre
** Last update Fri May 18 16:14:22 2012 antoine maitre
*/

#include "parser.h"

void		epur_pars(t_pars **pars)
{
  t_pars	*tmp;
  t_pars	*tmp2;

  tmp2 = (*pars);
  tmp = NULL;
  while ((*pars))
    {
      if ((*pars)->token && (*pars)->token[0] == ';')
	{
	  if ((*pars)->next && (*pars)->next->token && (*pars)->next->token[0] == ';')
	    {
	      tmp = (*pars)->next;
	      (*pars)->next = tmp->next;
	      if (tmp->next)
		tmp->next->prev = (*pars);
	      free(tmp->token);
	      free(tmp);
	    }
	  else
	    (*pars) = (*pars)->next;
	}
      else
	(*pars) = (*pars)->next;
    }
  (*pars) = tmp2;
}
