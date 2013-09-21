/*
** pipe.c for pipe in /home/dell-a_f/42sh/execution
** 
** Made by florian dell'aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Sun May 20 14:49:41 2012 florian dell'aiera
** Last update Sun May 20 15:41:50 2012 antoine knockaert
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<sys/wait.h>
#include	<sys/types.h>
#include	"../parser/parser.h"
#include	"../42sh.h"
#include	"../lib/my.h"
#include	"execution.h"

int		exec_ft_fils(t_pars *pars, int pipefd[2], t_glob *glob)
{
  int		error;

  close(pipefd[0]);
  error = dup2(pipefd[1], 1);
  if (error == -1)
    {
      my_putstr("error on dup2\n");
      return (-1);
    }
  else
    {
      error = search_pipe(pars->arg, glob, pars);
      close(pipefd[1]);
      return (error);
    }
}

int		exec_ft_pere(t_pars *pars, int pipefd[2], t_glob *glob)
{
  int		error;

  close(pipefd[1]);
  error = dup2(pipefd[0], 0);
  if (error == -1)
    {
      my_perror("Error on dup2.\n", 2, -1, 1);
      return (-1);
    }
  else
    {
      if (pars && pars->prev->right && pars->prev->right->token
	  && my_match(pars->prev->right->token, PIPE))
	{
	  pipe_only(pars->prev->right->left, glob);
	}
      else
	error = search_pipe(pars->prev->right->arg, glob,
			    pars->prev->right);
      close(pipefd[0]);
      return (error);
    }
}

int		pipe_only(t_pars *pars, t_glob *glob)
{
  int	pipefd[2];
  int	pid;
  int	error;

  error = pipe(pipefd);
  check_error(error);
  if ((pid = fork()) == -1)
    {
      return (my_perror("Error on fork.\n", 2, 0, 1));
    }
  if (pid == 0)
    {
      error = exec_ft_fils(pars, pipefd, glob);
    }
  else
    {
      error = exec_ft_pere(pars, pipefd, glob);
    }
  return (error);
}
