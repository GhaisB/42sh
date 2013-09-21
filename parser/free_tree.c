/*
** free_tree.c for free in /home/maitre_c//Mes_Programmes/prog
** 
** Made by antoine maitre
** Login   <maitre_c@epitech.net>
** 
** Started on  Fri May 18 16:21:18 2012 antoine maitre
** Last update Fri May 18 16:23:55 2012 antoine maitre
*/

#include	"parser.h"

void		free_the_tree(t_pars **pars)
{
  if ((*pars)->left)
    free_the_tree(&(*pars)->left);
  if ((*pars)->right)
    free_the_tree(&(*pars)->right);
  if ((*pars)->command)
    xfree((*pars)->command);
  if ((*pars)->redir)
    xfree((*pars)->redir);
  if ((*pars)->redir_fich)
    xfree((*pars)->redir_fich);
  if ((*pars)->token)
    xfree((*pars)->token);
  if ((*pars)->arg)
    free_wtb((*pars)->arg);
  if ((*pars))
    {
      xfree((*pars));
      (*pars) = NULL;
    }
}
