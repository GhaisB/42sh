/*
** check_access.c for 42 in /home/dell-a_f/42sh/execution
** 
** Made by florian dell'aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Thu May 17 15:49:41 2012 florian dell'aiera
** Last update Thu May 17 17:18:02 2012 florian dell'aiera
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	"../parser/parser.h"
#include	"../42sh.h"
#include	"../lib/my.h"
#include	"execution.h"

int		check_access(char *pathname)
{
  int		a;
  int		mode;

  mode = W_OK | R_OK;
  if (pathname == NULL)
    return (-1);
  a = access(pathname, mode);
  if (a == -1)
    {
      printf("Error on file access\n");
      return (-1);
    }
  return (0);
}
