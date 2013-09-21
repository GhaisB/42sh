/*
** execution_bin.c for 42sh in /home/dell-a_f/42sh/execution
** 
** Made by florian dell'aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Thu May 17 15:51:01 2012 florian dell'aiera
** Last update Thu May 17 16:33:18 2012 florian dell'aiera
*/

#include	<unistd.h>
#include	"../parser/parser.h"
#include	"../42sh.h"
#include	"../lib/my.h"
#include	"execution.h"

int		execution_bin(char **tabl, t_way *pt)
{
  int	check;

  check = execve(pt->way_to_exec, tabl, pt->c_env);
  if (check == -1)
    {
      printf("42sh: Error on execve\n");
      exit(EXIT_FAILURE);
    }
  return (1);
}
