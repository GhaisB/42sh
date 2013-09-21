/*
** check_error.c for 42 in /home/dell-a_f/42sh/execution
** 
** Made by florian dell'aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Thu May 17 16:01:54 2012 florian dell'aiera
** Last update Thu May 17 17:38:59 2012 florian dell'aiera
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<sys/wait.h>
#include	<sys/types.h>
#include	"../parser/parser.h"
#include	"../42sh.h"
#include	"../lib/my.h"
#include	"execution.h"

int		check_error(int error)
{
  if (error == -1)
    {
      my_putstr("error pipe\n");
      return (0);
    }
  return (error);
}
