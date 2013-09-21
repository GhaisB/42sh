/*
** execution.c for 42 in /home/dell-a_f/42sh/execution
** 
** Made by florian dell'aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Thu May 17 15:58:58 2012 florian dell'aiera
** Last update Sun May 20 15:45:44 2012 antoine knockaert
*/

#include	<sys/types.h>
#include	<sys/wait.h>
#include	"../parser/parser.h"
#include	"../42sh.h"
#include	"../lib/my.h"
#include	"execution.h"

int		execute_member(t_pars *pars, char *token, t_glob *glob, int side)
{
  if (token && (!my_match(token, PIPE)))
    pars->status = exec_gnral(pars->arg, glob, pars->redir , pars->redir_fich);
  if (side == 0 && my_match(token, AND) && pars && pars->status != 0)
    return (0);
  if (side == 0 && my_match(token, OR) && pars && pars->status == 0)
    return (0);
  gere_status(pars->status);
  return (1);
}

void		execution(t_pars *pars, t_glob *glob)
{
  if (pars && pars->token && my_match(pars->token, PIPE))
    do_fork_pipe(pars->left, glob);
  else
    {
      if (pars->left && pars->left->token)
	execution(pars->left, glob);
      else if (pars->left && pars->token && (!my_match(pars->token, PIPE)))
	if (!execute_member(pars->left, pars->token, glob, 0))
	  return ;
      if (pars->right && pars->right->token)
	execution(pars->right, glob);
      else if (pars->right && pars->token && (!my_match(pars->token, PIPE)))
	if (!execute_member(pars->right, pars->token, glob, 1))
	  return ;
    }

}
