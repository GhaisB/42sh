/*
** check_builtins.c for 42 in /home/dell-a_f/42sh/execution
** 
** Made by florian dell'aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Thu May 17 16:01:02 2012 florian dell'aiera
** Last update Sun May 20 16:25:37 2012 florian dell'aiera
*/

#include	"../parser/parser.h"
#include	"../42sh.h"
#include	"../lib/my.h"
#include	"execution.h"

int	check_builtins(t_glob *glob, char **tabl, t_way *pt)
{
  int	i;
  int	cpt;
  int	status;

  i = 0;
  cpt = my_tablen(tabl);
  status = -5;
  pt->built = 0;
  while (glob->builtin[i])
    {
      if (my_match(glob->builtin[i], tabl[0]))
	{
	  pt->built = 1;
	  type_of_redir(tabl, pt, glob);
	  status = glob->builtin_fc[i](cpt, tabl, glob);
	  return (status);
	}
      i++;
    }
  return (status);
}
