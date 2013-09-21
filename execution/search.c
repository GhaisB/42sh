/*
** search.c for 42 in /home/dell-a_f/42sh/execution
** 
** Made by florian dell'aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Thu May 17 16:02:57 2012 florian dell'aiera
** Last update Thu May 17 16:03:31 2012 florian dell'aiera
*/

#include	"../parser/parser.h"
#include	"../42sh.h"
#include	"../lib/my.h"
#include	"execution.h"

int		search(char **tabl, t_glob *glob, char *type, char *filename)
{
  t_way		pt;
  char		*path;
  char		**bin;
  int		check;
  int		status;

  check = 1;
  path = my_getenv("PATH", glob->env);
  copy_value(&pt, type, filename);
  status = check_builtins(glob, tabl, &pt);
  if (pt.built != 1)
    check_bin(tabl, &pt, glob, &status);
  if (path != NULL && pt.built != 1 && pt.i != 1)
    {
      bin = my_str_to_wordtab(path, ':');
      check = check_path(bin, tabl[0], &pt);
      check = error(check);
      if (check == 0)
	return (-10);
      end_of_way(&pt, tabl[0]);
      status = func_to_fork(tabl, &pt, glob);
    }
  return (status);
}
