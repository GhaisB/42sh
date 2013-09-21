/*
** func_to_fork.c for 42 in /home/dell-a_f/42sh/execution
** 
** Made by florian dell'aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Thu May 17 15:59:08 2012 florian dell'aiera
** Last update Sun May 20 16:54:48 2012 antoine knockaert
*/

#include	<sys/types.h>
#include	<sys/wait.h>
#include	<unistd.h>
#include	"../parser/parser.h"
#include	"../42sh.h"
#include	"../lib/my.h"
#include	"execution.h"

int		func_to_fork(char **tabl, t_way *pt, t_glob *glob)
{
  pid_t		pid;
  int		status;

  status = 0;
  pid = fork();
  if (pid == -1)
    {
      printf("error on fork\n");
      return (0);
    }
  if (pid == 0)
    type_of_redir(tabl, pt, glob);
  else
    {
      while ((waitpid(pid, &status, WNOHANG)) == 0);
      return (status);
    }
  return (-1);
}
