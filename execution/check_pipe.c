/*
** check_pipe.c for 42 in /home/dell-a_f/42sh/execution
** 
** Made by florian dell'aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Thu May 17 15:51:50 2012 florian dell'aiera
** Last update Thu May 17 17:40:36 2012 florian dell'aiera
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<sys/stat.h>
#include	<sys/types.h>
#include	<fcntl.h>
#include	"../parser/parser.h"
#include	"../42sh.h"
#include	"../lib/my.h"
#include	"execution.h"

int		check_pipe(int *pipefd)
{
  if (pipe(pipefd) == -1)
    {
      my_putstr("Error on pipe.\n");
      return (-1);
    }
  return (0);
}
