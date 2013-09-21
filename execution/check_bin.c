/*
** check_bin.c for 42 in /home/dell-a_f/42sh/execution
** 
** Made by florian dell'aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Thu May 17 15:51:31 2012 florian dell'aiera
** Last update Sun May 20 16:32:36 2012 florian dell'aiera
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<unistd.h>
#include	"../parser/parser.h"
#include	"../42sh.h"
#include	"../lib/my.h"
#include	"execution.h"

int		check_bin(char **tabl, t_way *pt, t_glob *glob, int *status)
{
  if (tabl != NULL && tabl[0] != NULL)
    {
      if (access(tabl[0], F_OK) == 0)
	{
	  if (access(tabl[0], X_OK) == 0)
	    {
	      pt->way_to_exec = tabl[0];
	      *status = func_to_fork(tabl, pt, glob);
	      pt->i = 1;
	      return (*status);
	    }
	}
      pt->i = 0;
      return (-10);
    }
  else
    return (-10);
}
