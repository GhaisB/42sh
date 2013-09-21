/*
** type_of_redir.c for 42 in /home/dell-a_f/42sh/execution
** 
** Made by florian dell'aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Thu May 17 16:00:53 2012 florian dell'aiera
** Last update Sun May 20 16:34:30 2012 florian dell'aiera
*/

#include	"../parser/parser.h"
#include	"../42sh.h"
#include	"../lib/my.h"
#include	"execution.h"

void		type_of_redir(char **tabl, t_way *pt, t_glob *glob)
{
  int		fd;

  pt->c_env = copy_env(glob, pt->c_env, pt);
  if (my_match(pt->c_type, D_RIGHT_RED) == 1)
    fd = d_redir_right(pt);
  if (my_match(pt->c_type, RIGHT_RED) == 1)
    fd = redir_right(pt);
  if (my_match(pt->c_type, D_LEFT_RED) == 1)
    d_redir_left(pt);
  if (my_match(pt->c_type, LEFT_RED) == 1)
    fd = redir_left(pt);
  if (pt->built != 1)
    execution_bin(tabl, pt);
  if (my_match(pt->c_type, D_RIGHT_RED) == 1 ||
      my_match(pt->c_type, RIGHT_RED) == 1)
    xclose(fd);
  if (my_match(pt->c_type, D_LEFT_RED) == 1 ||
      my_match(pt->c_type, LEFT_RED) == 1)
    xclose(fd);
  xfree(pt->c_file);
  xfree(pt->c_type);
  free_wtb(pt->c_env);
}
