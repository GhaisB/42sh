/*
** do_fork_pipe.c for do_fork_pipe.c in /home/dell-a_f/42sh/execution
** 
** Made by florian dell'aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Wed May 16 11:09:25 2012 florian dell'aiera
** Last update Sun May 20 15:45:38 2012 antoine knockaert
*/

#include	<sys/types.h>
#include	<sys/wait.h>
#include	"../parser/parser.h"
#include	"../42sh.h"
#include	"../lib/my.h"
#include	"execution.h"

void		do_fork_pipe(t_pars *pars, t_glob *glob)
{
  int		pid;
  int		status;

  pid = fork();
  if (pid == 0)
    pars->status = pipe_only(pars, glob);
  else
    while ((waitpid(pid, &status, WNOHANG)) == 0);
}
