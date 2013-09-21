/*
** execution_general.c for 42 in /home/dell-a_f/42sh/execution
** 
** Made by florian dell'aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Thu May 17 16:12:34 2012 florian dell'aiera
** Last update Thu May 17 16:12:35 2012 florian dell'aiera
*/

#include	"../parser/parser.h"
#include	"../42sh.h"
#include	"../lib/my.h"
#include	"execution.h"

int		exec_gnral(char **tabl, t_glob *glob, char *type, char *filename)
{
  int		status;

  status = search(tabl, glob, type, filename);
  return (status);
}
